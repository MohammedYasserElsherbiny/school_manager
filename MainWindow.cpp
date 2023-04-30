#include "MainWindow.h"
#include <cmath>
MainWindow::MainWindow()
{
    // Setup global Scene
    scene = new QGraphicsScene();

    // Get Display Resolution
    screen = QGuiApplication::primaryScreen();
    QRect  screenGeometry = screen->geometry();
    width = 900; // screenGeometry.width()
    height = 600; // screenGeometry.height()

    // Set scene properties
    scene->setSceneRect(0,0, width, height); // TODO: Improve screen size



    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);





    // Btn Demo
    startBtn = new QPushButton();
    startBtn->setText("ابدا");

    backBtn = new QPushButton();
    backBtn->setText("عوده");




    startBtnProxy = scene->addWidget(startBtn);
    startBtnProxy->setPos(width/2 - startBtnProxy->boundingRect().width()/2,
                          height - startBtnProxy->boundingRect().height() - 20);

    backBtnProxy = scene->addWidget(backBtn);
    backBtnProxy->setPos(width/8 - backBtnProxy->boundingRect().width()+50,
                          height - backBtnProxy->boundingRect().height() - 350);

    backBtn->hide();
    //document_preview_btn->hide();


    // create on click event listeners
    QObject::connect(startBtn, &QPushButton::clicked, this, &MainWindow::showGenderSelectionWindow);
}

void MainWindow::initWindows()
{
    // Init Windows
    gender_selection_window = new Gender_Selection();
    document_viewer = new Document_Viewer();
    grade_options_window = new GradeOptions();
    grade_selection_window = new GradeSelection();
}

void MainWindow::clearScene()
{
    foreach (QGraphicsItem *item, scene->items()) {
        if(item != backBtnProxy)
        item->hide();
            //scene->removeItem(item);
    }
}

void MainWindow::show_window()
{


    scene->setBackgroundBrush(QBrush(QImage(":/Assets/Images/start.jpg").scaledToWidth(width)));

    startBtn->show();

    backBtn->hide();

}

void MainWindow::showGenderSelectionWindow()
{
    clearScene();

    gender_selection_window->show_window();

}

//for document viwer

void MainWindow::fileNames()
{
    fileOpener();
    string path;
    int tempPlace=0;
    ifstream ifile(storge_file_names[setFileNum()]);
    while(getline(ifile, path))
    {

        string name;
        string exten;
        bool dotFlag= false;
        int path_size=path.size();
        for(int i=path_size-1;i>=0;i--)
        {
            if(path[i]=='.')
            {
                dotFlag= true;
                reverse(exten.begin(),exten.end());
                continue;
            }

            if(!dotFlag)
            {
                exten.push_back(path[i]);
                continue;
            }

            if(path[i]=='/')
            {
                break;
            }

            name.push_back(path[i]);
        }

        reverse(name.begin(),name.end());

        map < int , pair < string , pair < string , string > > > temp;
        temp[tempPlace].first=path;
        temp[tempPlace].second.first=name;
        temp[tempPlace].second.second=exten;

//        names[setFileNum()][tempPlace].first=path;
//        names[setFileNum()][tempPlace].second.first=name;
//        names[setFileNum()][tempPlace].second.second=exten;
        if(freqNames[temp]!=-1)
        {
            names.push_back(temp);
            freqNames[temp]=-1;

        }
        tempPlace++;
    }
    fileCloser();
}


void MainWindow::fileOpener()
{
    storge_files[storge_file_names[setFileNum()]].open(storge_file_names[setFileNum()],ios::app);
}

void MainWindow::fileCloser()
{
    //storge_files[storge_file_names[setFileNum()]].close();

    for(auto tempFileNames : storge_file_names)
    {
        storge_files[tempFileNames].close();
    }
}

int MainWindow::setFileNum()
{
    string gen=gender,gra=grade,opt=option;


    if(gen=="بنات")
    {
        if(gra=="مرحلة الثانوي")
        {
            if(opt=="اضافي")
            {
                return 0;
            }
            else if(opt=="التعاميم")
            {
                return 1;
            }
            else if(opt=="الخطة والتسجيل")
            {
                return 2;
            }
            else
            {
                return 3;
            }
        }
        else if(gra=="مرحلة المتوسط")
        {
            if(opt=="اضافي")
            {
                return 4;
            }
            else if(opt=="التعاميم")
            {
                return 5;
            }
            else if(opt=="الخطة والتسجيل")
            {
                return 6;
            }
            else
            {
                return 7;
            }
        }
        else if(gra=="مرحلة الروضة")
        {
            if(opt=="اضافي")
            {
                return 8;
            }
            else if(opt=="التعاميم")
            {
                return 9;
            }
            else if(opt=="الخطة والتسجيل")
            {
                return 10;
            }
            else
            {
                return 11;
            }
        }
        else
        {
            if(opt=="اضافي")
            {
                return 12;
            }
            else if(opt=="التعاميم")
            {
                return 13;
            }
            else if(opt=="الخطة والتسجيل")
            {
                return 14;
            }
            else
            {
                return 15;
            }
        }
    }
    else if(gen=="بنين")
    {
        if(gra=="مرحلة الثانوي")
        {
            if(opt=="اضافي")
            {
                return 16;
            }
            else if(opt=="التعاميم")
            {
                return 17;
            }
            else if(opt=="الخطة والتسجيل")
            {
                return 18;
            }
            else
            {
                return 19;
            }
        }
        else if(gra=="مرحلة المتوسط")
        {
            if(opt=="اضافي")
            {
                return 20;
            }
            else if(opt=="التعاميم")
            {
                return 21;
            }
            else if(opt=="الخطة والتسجيل")
            {
                return 22;
            }
            else
            {
                return 23;
            }
        }
        else if(gra=="مرحلة الابتدائي")
        {
            if(opt=="اضافي")
            {
                return 24;
            }
            else if(opt=="التعاميم")
            {
                return 25;
            }
            else if(opt=="الخطة والتسجيل")
            {
                return 26;
            }
            else
            {
                return 27;
            }
        }

    }
    else
    {
        return 0;
    }
}

void MainWindow::generateFiles()
{
    string male="Male",female="Female",add="Additional",cir="Circular",pla="Plan",repor="Report",kin="Kinder",inter="Intermediate",high="High school",pri="Primary";

    for(int i=0;i<2;i++)
    {
        string temp="Storge";

        if(i==1)
        {
            temp+=male;
        }
        else
        {
            temp+=female;
        }

        vector <string> fourTemp;
        for(int j=0;j<4;j++)
        {
            fourTemp.push_back(temp+pri);
            //break;


            fourTemp.push_back(temp+inter);
            //break;


            fourTemp.push_back(temp+high);
            //break;

            if(i!=1)
                fourTemp.push_back(temp+kin);
            //break;


            vector <string> lastTemp;
            for(int l=0;l<fourTemp.size()*4;l++)
            {
                if(l<4)
                {
                    lastTemp.push_back(fourTemp[0]);
                }
                else if(l<8)
                {
                    lastTemp.push_back(fourTemp[1]);
                }
                else if(l<12)
                {
                    lastTemp.push_back(fourTemp[2]);
                }
                else
                {
                    lastTemp.push_back(fourTemp[3]);
                }
            }

            for(int k=0;k<(fourTemp.size()*4);k++)
            {
                string temp1,temp2,temp3,temp4;
                if(k<4)
                {
                    temp1=lastTemp[k]+add;
                    temp1+=".txt";
                    temp_storge_file_names.insert(temp1);
                    storge_files[temp1].open(temp1,ios::app);
                    temp2=lastTemp[k]+cir;
                    temp2+=".txt";
                    temp_storge_file_names.insert(temp2);
                    storge_files[temp2].open(temp2,ios::app);
                    temp3=lastTemp[k]+pla;
                    temp3+=".txt";
                    temp_storge_file_names.insert(temp3);
                    storge_files[temp3].open(temp3,ios::app);
                    temp4=lastTemp[k]+repor;
                    temp4+=".txt";
                    temp_storge_file_names.insert(temp4);
                    storge_files[temp4].open(temp4,ios::app);
                    //break;
                }
                else if (k<8)
                {
                    temp1=lastTemp[k]+add;
                    temp1+=".txt";
                    temp_storge_file_names.insert(temp1);
                    storge_files[temp1].open(temp1,ios::app);
                    temp2=lastTemp[k]+cir;
                    temp2+=".txt";
                    temp_storge_file_names.insert(temp2);
                    storge_files[temp2].open(temp2,ios::app);
                    temp3=lastTemp[k]+pla;
                    temp3+=".txt";
                    temp_storge_file_names.insert(temp3);
                    storge_files[temp3].open(temp3,ios::app);
                    temp4=lastTemp[k]+repor;
                    temp4+=".txt";
                    temp_storge_file_names.insert(temp4);
                    storge_files[temp4].open(temp4,ios::app);
                    //break;
                }
                else if(k<12)
                {
                    temp1=lastTemp[k]+add;
                    temp1+=".txt";
                    temp_storge_file_names.insert(temp1);
                    storge_files[temp1].open(temp1,ios::app);
                    temp2=lastTemp[k]+cir;
                    temp2+=".txt";
                    temp_storge_file_names.insert(temp2);
                    storge_files[temp2].open(temp2,ios::app);
                    temp3=lastTemp[k]+pla;
                    temp3+=".txt";
                    temp_storge_file_names.insert(temp3);
                    storge_files[temp3].open(temp3,ios::app);
                    temp4=lastTemp[k]+repor;
                    temp4+=".txt";
                    temp_storge_file_names.insert(temp4);
                    storge_files[temp4].open(temp4,ios::app);

                    //break;
                }
                else
                {
                    temp1=lastTemp[k]+add;
                    temp1+=".txt";
                    temp_storge_file_names.insert(temp1);
                    storge_files[temp1].open(temp1,ios::app);
                    temp2=lastTemp[k]+cir;
                    temp2+=".txt";
                    temp_storge_file_names.insert(temp2);
                    storge_files[temp2].open(temp2,ios::app);
                    temp3=lastTemp[k]+pla;
                    temp3+=".txt";
                    temp_storge_file_names.insert(temp3);
                    storge_files[temp3].open(temp3,ios::app);
                    temp4=lastTemp[k]+repor;
                    temp4+=".txt";
                    temp_storge_file_names.insert(temp4);
                    storge_files[temp4].open(temp4,ios::app);
                    //break;

                }
            }
        }

    }

    //coping set to the vector

    for(string str : temp_storge_file_names)
    {
        storge_file_names.push_back(str);
    }
}

void MainWindow::generateFolders()
{

    //male
    filesystem::create_directories("C:/school_manager/male/Primary/additional");
    filesystem::create_directories("C:/school_manager/male/Primary/Circular");
    filesystem::create_directories("C:/school_manager/male/Primary/Plan");
    filesystem::create_directories("C:/school_manager/male/Primary/Reports");
    filesystem::create_directories("C:/school_manager/male/Intermediate/additional");
    filesystem::create_directories("C:/school_manager/male/Intermediate/Circular");
    filesystem::create_directories("C:/school_manager/male/Intermediate/Plan");
    filesystem::create_directories("C:/school_manager/male/Intermediate/Reports");
    filesystem::create_directories("C:/school_manager/male/High school/additional");
    filesystem::create_directories("C:/school_manager/male/High school/Circular");
    filesystem::create_directories("C:/school_manager/male/High school/Plan");

    //female
    filesystem::create_directories("C:/school_manager/female/Primary/additional");
    filesystem::create_directories("C:/school_manager/female/Primary/Circular");
    filesystem::create_directories("C:/school_manager/female/Primary/Plan");
    filesystem::create_directories("C:/school_manager/female/Primary/Reports");
    filesystem::create_directories("C:/school_manager/female/Intermediate/additional");
    filesystem::create_directories("C:/school_manager/female/Intermediate/Circular");
    filesystem::create_directories("C:/school_manager/female/Intermediate/Plan");
    filesystem::create_directories("C:/school_manager/female/Intermediate/Reports");
    filesystem::create_directories("C:/school_manager/female/High school/additional");
    filesystem::create_directories("C:/school_manager/female/High school/Circular");
    filesystem::create_directories("C:/school_manager/female/High school/Plan");
    filesystem::create_directories("C:/school_manager/female/High school/Reports");
    filesystem::create_directories("C:/school_manager/female/Kindergarten/additional");
    filesystem::create_directories("C:/school_manager/female/Kindergarten/Circular");
    filesystem::create_directories("C:/school_manager/female/Kindergarten/Plan");
    filesystem::create_directories("C:/school_manager/female/Kindergarten/Reports");


}

void MainWindow::setMainItem()
{
    //place=abs(pla  ce);

    map < int , pair < string , pair < string , string > > >  temp12;
    int tempIdx;
    if(abs(place)==(int)(names.size()-1)&&(place<0))
    {
        place=0;
    }
    if(place<0)
    {
        tempIdx=names.size()+place;
    }
    else
    {
        tempIdx=place%names.size();
    }
    temp12=names[tempIdx];
    string plzWorkStr;
    for(auto p : temp12)
    {
        if(p.second.second.second =="")
            continue;
        plzWorkStr=p.second.second.second;
    }

    if(filesystem::is_empty(storge_file_names[setFileNum()]))
    {
        document_preview_btn->setText("لا يوجد ملفات");
        document_preview_btn->setIcon(QIcon());
        return ;
    }
    else
    {
        document_preview_btn->setText(QString::fromStdString(currentName()));
    }




    if(plzWorkStr=="txt")
    {
        document_preview_btn->setIcon(QIcon(":/Assets/Images/images.png"));
        document_preview_btn->setIconSize(QSize(65, 65));
    }

    else if((plzWorkStr=="bmp")||(plzWorkStr=="jpg")||(plzWorkStr=="png"))
    {
        document_preview_btn->setIcon(QIcon(":/Assets/Images/Photos-new-icon.png"));
        document_preview_btn->setIconSize(QSize(65, 65));
    }

    else if(plzWorkStr=="xlsx"||plzWorkStr=="csv"||plzWorkStr=="xls")
    {
        document_preview_btn->setIcon(QIcon(":/Assets/Images/Microsoft Excel Vector PNG Images, Microsoft Excel Icon, Excel Icons, Microsoft Icons, Microsoft PNG Image For Free Download.jpg"));
        document_preview_btn->setIconSize(QSize(65, 65));
    }

    else if(plzWorkStr=="pptx"||plzWorkStr=="ppt"||plzWorkStr=="pot")
    {
        document_preview_btn->setIcon(QIcon(":/Assets/Images/Powerpoints Clipart Vector, Powerpoint Icon, Powerpoint Icons, Microsoft, Azure PNG Image For Free Download.jpg"));
        document_preview_btn->setIconSize(QSize(65, 65));
    }

    else if(plzWorkStr=="docx"||plzWorkStr=="doc")
    {
        document_preview_btn->setIcon(QIcon(":/Assets/Images/word.jpg"));
        document_preview_btn->setIconSize(QSize(65, 65));
    }
    else
    {
        document_preview_btn->setIcon(QIcon());
    }
}

string MainWindow::currentName()
{
    map < int , pair < string , pair < string , string > > > temp;
    int tempIdx;
    if(abs(place)==(int)(names.size()-1)&&(place<0))
    {
        place=0;
    }
    if(place<0)
    {
        tempIdx=names.size()+place;
    }
    else
    {
        tempIdx=place%names.size();
    }
    temp=names[tempIdx];
    return temp[tempIdx].second.first;
}


