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

using namespace std;

void Form::SearchClicked()
{
    
    //ShowWindow();
    x=-1;
    FileDisplayBox->clear();

    MySetWebPage temporary;
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
    else 
    {
        mergeSort(temp2, filenameComp);
    }
    //mergeSort(result, filenameComp);
   // mergeSort(result, ilk);
            for(list<WebPage*>::iterator it1 = temp2.begin(); it1!= temp2.end(); ++it1)
        {
            result.push_back(*it1);
        }

    for(vector<WebPage*>::iterator it2 = result.begin(); it2!= result.end(); ++it2)
    {
        stringstream temp;
        temp << (*it2)->filename() << " OL: " << (*it2)->all_links().size()<< " IL: " << (*it2)->incoming_links().size();
        string second_temp;
        second_temp = temp.str();
        QString Qstringythingy = QString::fromStdString(second_temp);

   
        FileDisplayBox->addItem(Qstringythingy);
    }
    return;
}

Form::Form(string index_filename)
{
    PageParser *parser = new MDparser();
    my_engine.add_parse_from_index_file(index_filename, parser);
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

    rightLayout->addWidget(rightLayoutLabel);
    rightLayout->addWidget(FileDisplayBox);
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
    secondSortedByFilenameButton = new QRadioButton("Sorted by filename");
    secondSortedByOutgoingButton = new QRadioButton("Sorted by outgoing links");
    secondSortedByIncomingButton = new QRadioButton("Sorted by incoming links");
    UpdateButton = new QPushButton("UPDATE SORT");

    secondleftLayout->addWidget(secondleftLayoutLabel);
    secondleftLayout->addWidget(WordDisplayBox);
    secondleftLayout->addWidget(UpdateButton);
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
    //connect(UpdateButton, SIGNAL(clicked()), this,SLOT(SortFiles(MySetWebPage holder1, MySetWebPage holder2)));
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
cout << "Testing part 1" <<filename << endl;
    QString qstr = QString::fromStdString(filename);
    secondWindow->setWindowTitle(qstr);


    WordDisplayBox->clear();
    stringstream os;
    os<<(*(result[x]));
    string str;
    str = os.str();
    cout << "Testing part 2 " <<str << endl;
    //cout << str << endl;
    QString Qstringythingy = QString::fromStdString(str);
    WordDisplayBox->addItem(Qstringythingy);
    //SortFiles(temp);
     ilt.clear();
    olt.clear();
    cout << "getting incoming links " << endl;
    if((*result[x]).incoming_links().size() > 0)
    {
        for(set<WebPage*>::iterator it1 = (*result[x]).incoming_links().begin(); it1!= (*result[x]).incoming_links().end(); ++it1)  
        {
            ilt.push_back(*it1);
        }
    }
    cout << "done getting incoming links" << endl;
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





