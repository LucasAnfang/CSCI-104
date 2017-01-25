#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QString>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QGroupBox>
#include <QDialog>
#include <QListWidget>
#include <QTextLayout>
#include <QRadioButton>
#include <QTextEdit>
#include "myset.h"
#include "webpage.h"
#include "searcheng.h"
#include "mdparser.h"
#include "util.h"
#include <vector>


class Form : public QWidget
{
Q_OBJECT

public:
   Form(string filename);
   ~Form();
   //int y;
       std::list<WebPage*>ilt;
           std::list<WebPage*>olt;

        std::vector<WebPage*>ilresult;
    std::vector<WebPage*>olresult;

   
private slots:
   void quit();
   void SearchClicked();
   void ShowWindow();
   void SortFiles();
   
   void SelectRow(int x);

   
   
private:
   int x;
       std::list<WebPage*> temp2;
       std::vector<WebPage*> result;
   QHBoxLayout *overallLayout;
   
   QVBoxLayout *rightLayout;
   QLabel *rightLayoutLabel;
   QListWidget *FileDisplayBox;
   QRadioButton *SortedByFilenameButton;
   QRadioButton *SortedByOutgoingButton;
   QRadioButton *SortedByIncomingButton;
   QVBoxLayout *subLayout; 
   QGroupBox *gb;  
   
   QVBoxLayout *leftLayout;
   QLabel *leftLayoutLabel;
   QLineEdit *UserInputBox;
   QRadioButton *AndButton;
   QRadioButton *OrButton;
   QRadioButton *OneWordButton;
   QPushButton *SearchButton;
   QPushButton *QuitButton;
   QPushButton *OpenLinkButton;
   SearchEng my_engine;

   //SUBLAYOUT SECTION AAAAAAGH 
   QWidget *secondWindow;
   QHBoxLayout *secondoverallLayout;
   //QPushButton *secondOpenLinkButton;
   


   QVBoxLayout *secondleftLayout;
   QLabel *secondleftLayoutLabel;
   QPushButton *UpdateButton;
   //QRadioButton *UpdateButton;
   QRadioButton *secondSortedByFilenameButton;
   QRadioButton *secondSortedByOutgoingButton;
   QRadioButton *secondSortedByIncomingButton;
   QVBoxLayout *secondsubLayout;    
   QGroupBox *secondgb;


   QVBoxLayout *secondrightLayout;
   QLabel *outgoingLabel;
   QListWidget *outgoingDisplayBox;   
   QLabel *incomingLabel;
   QListWidget *incomingDisplayBox;



   QListWidget *WordDisplayBox;


};
