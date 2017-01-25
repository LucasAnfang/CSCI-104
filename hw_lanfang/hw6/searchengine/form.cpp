#include "form.h"
#include "FilenameComp.h"
#include <iostream>
#include <set>
#include <vector>
#include <list>
#include <string>
#include <fstream>
#include <cctype>
#include <sstream>
#include <locale>
#include <QApplication>
#include "msort.h"
#include "IncomingLinkComp.h"
#include "OutgoingLinkComp.h"
#include "PageRankComp.h"
//#include "crawler.h"

using namespace std;

void Form::SearchClicked()
{

    //ShowWindow();
    x=-1;
    FileDisplayBox->clear();

    MySet<WebPage*> temporary;
    temp2.clear();
    result.clear();

    if(UserInputBox->text().isEmpty())
    {
        return;
    }



    istringstream iss(UserInputBox->text().toStdString());
    vector<string> query_words;
    string query_word;
    FilenameComp filenameComp;
    IncomingLinkComp ilk;
    OutgoingLinkComp olk;
    PageRankComp prk;
    while(iss>>ws>>query_word)
    {
        query_word = convToLower(query_word);
        query_words.push_back(query_word);
    }
    if(AndButton->isChecked())
    {
        temporary = my_engine.and_method( query_words);
    }
    else if(OrButton->isChecked())
    {
        temporary = my_engine.or_method( query_words);
    }
    else if(OneWordButton->isChecked())
    {
        if(query_words.size() > 1)
        {
            return;
        }
        else temporary = my_engine.one_word_method(query_word);
    }

    for(set<WebPage*>::iterator it1 = temporary.begin(); it1!= temporary.end(); ++it1)
    {
        temp2.push_back(*it1);
    }
    mergeSort(temp2, filenameComp);

    //THIS IS THE START OF MY PAGERANK
    double pageRanks[temp2.size()];
    double newPageRanks[temp2.size()];
    WebPage* pageGraph[temp2.size()];
    double initial_rank = 1.0/(temp2.size());
    //cout << initial_rank << endl;
    for(unsigned int i = 0; i < temp2.size(); i++ )
    {
        pageRanks[i] = initial_rank;
    }
    map<string, int> index_map;
    int index = 0;
    for(list<WebPage*>::iterator it1 = temp2.begin(); it1!= temp2.end(); ++it1)
    {
        pageGraph[index] = (*it1);
        index_map[(*it1)->filename()] = index;
        index++;
    }
    //double epsilon = 0.15;
    for(int j = 0; j < iteration; j++)
    {
//i will be the index of the node in the graph
        for(unsigned int i = 0; i < temp2.size(); i++)
        {
            //cout << "for node " << i <<" " << pageGraph[i]->filename() << endl;
            double holding = 0;
            newPageRanks[i] = 0;
            MySet<WebPage*> pred(pageGraph[i]->incoming_links());
            pred.insert(pageGraph[i]);
            for(MySet<WebPage*>::iterator it = pred.begin(); it!=pred.end(); ++it)
            {
                if(index_map.count((*it)->filename())==0)
                {
                     continue;
                }
                //cout << "the filename of the incoming link: " << (*it)->filename() << endl; 
                //double holding = 0;
                int index = index_map[(*it)->filename()];//.second;
                //cout << "index: " << index << " filename: " << (*it)->filename() << " incoming Links: " << (*it)->all_links().size() << endl;
                int outgoingSize = 0;
                //MySet<WebPage*> testing((*it)->outgoing_links());
                MySet<WebPage*> OLS((*it)->outgoing_links());
                OLS.insert((*it));
                for(MySet<WebPage*>::iterator it1 = OLS.begin(); it1!= OLS.end(); ++it1)
                {
                    if(index_map.count((*it1)->filename()))
                    {
                        outgoingSize++;
                    }
                }
                //cout << "the output size " << outgoingSize << endl;
                holding+=(pageRanks[index]/outgoingSize);
                //newPageRanks[i]+=(1-epsilon)*(pageRanks[index]/outgoingSize) +epsilon/temp2.size(); //weight this with epsilon
            }
            newPageRanks[i]=(1-epsilon)*holding+(epsilon)/temp2.size();
        }
        for(unsigned int i = 0; i < temp2.size(); i++)
        {
            pageRanks[i] = newPageRanks[i];
            //cout << "index: " << i << " Pagerank: " << newPageRanks[i] << endl;
        }
    }
    // for(unsigned int i = 0; i < temp2.size(); i++)
    // {
    //     //pageRanks[i] = newPageRanks[i];
    //     cout << "index: " << i << " Pagerank: " << pageRanks[i] << endl;
    // }
    int pageIt = 0;
    for(list<WebPage*>::iterator it1 = temp2.begin(); it1!= temp2.end(); ++it1)
    {
        (*it1)->add_page_rank(pageRanks[pageIt]);
        pageIt++;
    }



    //End of pagerank

    if(SortedByFilenameButton->isChecked())
    {

        mergeSort(temp2, filenameComp);
        //call mergesort to order by aphabetical
    }
    else if(SortedByOutgoingButton->isChecked())
    {
        mergeSort(temp2, olk);

        //call mergesort to order by number of outgoing links
    }
    else if(SortedByIncomingButton->isChecked())
    {
        mergeSort(temp2, ilk);
        //call mergesort to order by number of incoming links
    }
    else if(SortedByPageRankButton->isChecked())
    {
        mergeSort(temp2,prk);
    }
    else
    {
        mergeSort(temp2, prk);
    }

    for(list<WebPage*>::iterator it1 = temp2.begin(); it1!= temp2.end(); ++it1)
    {
        result.push_back(*it1);
    }


    for(vector<WebPage*>::iterator it2 = result.begin(); it2!= result.end(); ++it2)
    {
        stringstream temp;
        temp << (*it2)->filename() << " OL: " << (*it2)->outgoing_links().size()<< " IL: " << (*it2)->incoming_links().size() << " PageRank: " << (*it2)->page_rank();
        string second_temp;
        second_temp = temp.str();
        QString Qstringythingy = QString::fromStdString(second_temp);


        FileDisplayBox->addItem(Qstringythingy);
    }
    return;
}

Form::Form(string seed_filename,int iter, double ep)
{
    epsilon = ep;
    iteration=iter;
    //cout << "SeedFilename: " <<seed_filename << " OutputFilename: " << output_filename << endl;
    //string path;
    //ofstream out;
    //out.open(output_filename.c_str(),ios_base::out);
    PageParser *parser = new MDparser();
    my_engine.add_parse_from_index_file(seed_filename, parser);
    //cout << "done adding parse from index file" << endl;
    //my_crawler.crawler_add_parse_from_index_file(seed_filename, parser, path);
    //cout << "done with crawler add parse from index file" << endl;
    //my_crawler.populate_file(out);
    //out.close();




//home/student/hw_lanfang/hw_lanfang/hw4/Makefile


    //my_engine.ReturnMap();
    overallLayout = new QHBoxLayout();
    leftLayout = new QVBoxLayout();
    rightLayout = new QVBoxLayout();
    subLayout = new QVBoxLayout();
    gb = new QGroupBox();

    overallLayout->addLayout(leftLayout);
    overallLayout->addLayout(rightLayout);
    QGroupBox* gb = new QGroupBox("Sorted By: ");
    gb->setLayout(subLayout);


    //Left Layout setup
    leftLayoutLabel = new QLabel("Term(s) to Search:");
    UserInputBox = new QLineEdit();
    AndButton = new QRadioButton("AND CASE");
    OrButton = new QRadioButton("OR CASE");
    OneWordButton = new QRadioButton("ONE WORD CASE");
    SearchButton = new QPushButton("SEARCH / REFRESH");
    OpenLinkButton = new QPushButton("OPEN LINK");
    connect(SearchButton,SIGNAL(clicked()),this,SLOT(SearchClicked()));


    connect(UserInputBox,SIGNAL(returnPressed()),this,SLOT(SearchClicked()));
    QuitButton = new QPushButton("QUIT");
    connect(QuitButton,SIGNAL(clicked()),this,SLOT(quit()));

    leftLayout->addWidget(leftLayoutLabel);
    leftLayout->addWidget(UserInputBox);
    leftLayout->addWidget(OpenLinkButton);
    leftLayout->addWidget(AndButton);
    leftLayout->addWidget(OrButton);
    leftLayout->addWidget(OneWordButton);
    leftLayout->addWidget(SearchButton);
    leftLayout->addWidget(QuitButton);

    //right layout
    FileDisplayBox = new QListWidget;

    rightLayoutLabel = new QLabel("Files:");
    SortedByFilenameButton = new QRadioButton("Sorted by filename");
    SortedByOutgoingButton = new QRadioButton("Sorted by outgoing links");
    SortedByIncomingButton = new QRadioButton("Sorted by incoming links");
    SortedByPageRankButton = new QRadioButton("Sorted by page rank");

    rightLayout->addWidget(rightLayoutLabel);
    rightLayout->addWidget(FileDisplayBox);
    subLayout->addWidget(SortedByPageRankButton);
    subLayout->addWidget(SortedByFilenameButton);
    subLayout->addWidget(SortedByOutgoingButton);
    subLayout->addWidget(SortedByIncomingButton);

    rightLayout->addWidget(gb);
    this->setWindowTitle("LUCAS ANFANG'S SEARCH ENGINE");

    //Setting the layout
    setLayout(overallLayout);


    //SUBLAYOUT SECTION AAAAAAGH
    secondWindow= new QWidget;
    secondoverallLayout = new QHBoxLayout();
    secondleftLayout = new  QVBoxLayout();
    secondrightLayout = new  QVBoxLayout();
    secondsubLayout = new  QVBoxLayout();
    secondgb = new QGroupBox();

    secondWindow->setLayout(secondoverallLayout);
    secondoverallLayout->addLayout(secondleftLayout);
    secondoverallLayout->addLayout(secondrightLayout);
    QGroupBox* secondgb = new QGroupBox("Sorted By: ");
    secondgb->setLayout(secondsubLayout);

    secondleftLayoutLabel = new QLabel("File Contents:");
    WordDisplayBox = new QListWidget();
//new
    secondOpenLinkButton = new QPushButton("OPEN LINK");

    secondSortedByFilenameButton = new QRadioButton("Sorted by filename");
    secondSortedByOutgoingButton = new QRadioButton("Sorted by outgoing links");
    secondSortedByIncomingButton = new QRadioButton("Sorted by incoming links");
    UpdateButton = new QPushButton("UPDATE SORT");

    secondleftLayout->addWidget(secondleftLayoutLabel);
    secondleftLayout->addWidget(WordDisplayBox);
    secondleftLayout->addWidget(UpdateButton);
//new
    secondleftLayout->addWidget(secondOpenLinkButton);

    secondsubLayout->addWidget(secondSortedByFilenameButton);
    secondsubLayout->addWidget(secondSortedByOutgoingButton);
    secondsubLayout->addWidget(secondSortedByIncomingButton);
    secondleftLayout->addWidget(secondgb);



    outgoingLabel = new QLabel("Outgoing files:");
    outgoingDisplayBox = new QListWidget;
    incomingLabel = new QLabel("Incoming files:");
    incomingDisplayBox = new QListWidget;

    secondrightLayout->addWidget(outgoingLabel);
    secondrightLayout->addWidget(outgoingDisplayBox);
    secondrightLayout->addWidget(incomingLabel);
    secondrightLayout->addWidget(incomingDisplayBox);

    // connect(FileDisplayBox,SIGNAL(itemDoubleClicked(QListWidgetItem*)),this,SLOT(ShowWindow(currentRow())));
    connect(FileDisplayBox,SIGNAL(currentRowChanged(int)), this, SLOT(SelectRow(int)));
    connect(UpdateButton, SIGNAL(clicked()), this,SLOT(SortFiles()));
    connect(OpenLinkButton,SIGNAL(clicked()),this,SLOT(ShowWindow()));
    //connect(UpdateButton, SIGNAL(clicked()), this,SLOT(SortFiles(MySet<WebPage*> holder1, MySet<WebPage*> holder2)));
//    connect(OpenLinkButton,SIGNAL(clicked()),this,SLOT(ShowWindow(FileDisplayBox->currentRow())));





}
void Form::SelectRow(int y)
{

    x = y;
}

Form::~Form()
{
    delete incomingDisplayBox;
    delete incomingLabel;
    delete outgoingDisplayBox;
    delete outgoingLabel;

    delete secondSortedByIncomingButton;
    delete secondSortedByOutgoingButton;
    delete secondSortedByFilenameButton;

    delete secondsubLayout;
    delete secondgb;
    delete UpdateButton;
    delete WordDisplayBox;

    delete secondleftLayoutLabel;
    delete secondrightLayout;
    delete secondleftLayout;
    delete secondoverallLayout;
    delete secondWindow;


    delete SortedByIncomingButton;
    delete SortedByOutgoingButton;
    delete SortedByFilenameButton;
    delete SortedByPageRankButton; 
    delete subLayout;
    delete gb;
    delete FileDisplayBox;
    delete rightLayoutLabel;

    delete QuitButton;
    delete SearchButton;
    delete OneWordButton;
    delete OrButton;
    delete AndButton;
    delete OpenLinkButton;
    delete UserInputBox;
    delete leftLayoutLabel;

    delete rightLayout;
    delete leftLayout;
    delete overallLayout;


}

void Form::ShowWindow()
{
    if(x==-1 || result.size()==0)
    {
        return;
    }
//    std::cout << "Called." << std::endl;
    //cout << x << endl;
    //cout<<result[x]->filename()<<endl;
    // int temp = x;
    incomingDisplayBox->clear();
    outgoingDisplayBox->clear();

    ilresult.clear();
    olresult.clear();
    string filename = result[x]->filename();
    QString qstr = QString::fromStdString(filename);
    secondWindow->setWindowTitle(qstr);


    WordDisplayBox->clear();
    stringstream os;
    os<<(*(result[x]));
    string str;
    str = os.str();
    //cout << str << endl;
    QString Qstringythingy = QString::fromStdString(str);
    WordDisplayBox->addItem(Qstringythingy);
    //SortFiles(temp);
    ilt.clear();
    olt.clear();
    if((*result[x]).incoming_links().size() > 0)
    {
        for(set<WebPage*>::iterator it1 = (*result[x]).incoming_links().begin(); it1!= (*result[x]).incoming_links().end(); ++it1)
        {
            ilt.push_back(*it1);
        }
    }
    // list<WebPage*>olt;
    if((*result[x]).outgoing_links().size() > 0)
    {
        for(set<WebPage*>::iterator it1 = (*result[x]).outgoing_links().begin(); it1!= (*result[x]).outgoing_links().end(); ++it1)
        {
            olt.push_back(*it1);
        }
    }
    // vector<WebPage*>ilresult;
    // vector<WebPage*>olresult;
    for(list<WebPage*>::iterator it1 = ilt.begin(); it1!= ilt.end(); ++it1)
    {
        ilresult.push_back(*it1);
    }
    for(list<WebPage*>::iterator it2 = olt.begin(); it2!= olt.end(); ++it2)
    {
        olresult.push_back(*it2);
    }
    //incomingDisplayBox->clear();
    //outgoingDisplayBox->clear();
    for(vector<WebPage*>::iterator it2 = ilresult.begin(); it2!= ilresult.end(); ++it2)
    {
        stringstream temp;
        temp << (*it2)->filename() << " OL: " << (*it2)->all_links().size()<< " IL: " << (*it2)->incoming_links().size();
        string second_temp;
        second_temp = temp.str();
        QString Qstringythingy = QString::fromStdString(second_temp);


        incomingDisplayBox->addItem(Qstringythingy);
    }
    for(vector<WebPage*>::iterator it2 = olresult.begin(); it2!= olresult.end(); ++it2)
    {
        stringstream temp;
        temp << (*it2)->filename() << " OL: " << (*it2)->all_links().size()<< " IL: " << (*it2)->incoming_links().size();
        string second_temp;
        second_temp = temp.str();
        QString Qstringythingy = QString::fromStdString(second_temp);


        outgoingDisplayBox->addItem(Qstringythingy);
    }

    //connect(incomingDisplayBox,SIGNAL(currentRowChanged(int)), this, SLOT(SelectRow()));
    //connect(outgoingDisplayBox,SIGNAL(currentRowChanged(int)), this, SLOT(SelectRow()));

    secondWindow->show();


}



void Form::quit()
{
    QApplication::quit();
}

void Form::SortFiles()
{

    incomingDisplayBox->clear();
    outgoingDisplayBox->clear();

    FilenameComp filenameComp;
    IncomingLinkComp ilk;
    OutgoingLinkComp olk;



    if(secondSortedByFilenameButton->isChecked())
    {

        mergeSort(ilt, filenameComp);
        mergeSort(olt, filenameComp);
        //call mergesort to order by aphabetical
    }
    else if(secondSortedByOutgoingButton->isChecked())
    {
        mergeSort(ilt, olk);
        mergeSort(olt, olk);

        //call mergesort to order by number of outgoing links
    }
    else if(secondSortedByIncomingButton->isChecked())
    {
        mergeSort(ilt, ilk);
        mergeSort(olt, ilk);

        //call mergesort to order by number of incoming links
    }
    else
    {
        mergeSort(ilt, filenameComp);
        mergeSort(olt, filenameComp);
    }

    vector<WebPage*>ilresult;
    vector<WebPage*>olresult;
    for(list<WebPage*>::iterator it1 = ilt.begin(); it1!= ilt.end(); ++it1)
    {
        ilresult.push_back(*it1);
    }
    for(list<WebPage*>::iterator it2 = olt.begin(); it2!= olt.end(); ++it2)
    {
        olresult.push_back(*it2);
    }


    for(vector<WebPage*>::iterator it2 = ilresult.begin(); it2!= ilresult.end(); ++it2)
    {
        stringstream temp;
        temp << (*it2)->filename() << " OL: " << (*it2)->all_links().size()<< " IL: " << (*it2)->incoming_links().size();
        string second_temp;
        second_temp = temp.str();
        QString Qstringythingy = QString::fromStdString(second_temp);


        incomingDisplayBox->addItem(Qstringythingy);
    }
    for(vector<WebPage*>::iterator it2 = olresult.begin(); it2!= olresult.end(); ++it2)
    {
        stringstream temp;
        temp << (*it2)->filename() << " OL: " << (*it2)->all_links().size()<< " IL: " << (*it2)->incoming_links().size();
        string second_temp;
        second_temp = temp.str();
        QString Qstringythingy = QString::fromStdString(second_temp);


        outgoingDisplayBox->addItem(Qstringythingy);
    }
}





