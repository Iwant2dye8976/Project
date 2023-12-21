#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<fstream>
#include<string.h>
#include<conio.h>
using namespace std;
class Lib
{
   public:
       char TenSach[100],TenTacGia[50],ID[50],ID1[20];
       int q,B,p;
       Lib()
       {
           strcpy(TenSach,"Ko co ten sach");
           strcpy(TenTacGia,"Ko co ten tac gia");
           strcpy(ID1,"Ko co");
           strcpy(ID,"Ko co ma ID");
           q=0; 
           B=0;
           p=0; 
       }
          void get();
          void SV();
          void pass();
          void QuanLy();
          void password();
          void getdata();
          void show(int);
          void DSsach(int);
          void modify();
          void see(int);
          int branch(int);
          void issue();
          void der(char[],int,int);
          void fine(int,int,int,int,int,int);
};
void Lib::getdata()
{
                    int i;
                    fflush(stdin);
                    cout<<"\n\t\tDien thong tin sach :-\n";
                    cout<<"\n\t\tNhap ten sach : ";
                    cin.getline(TenSach,100);
                    for(i=0;TenSach[i]!='\0';i++)
                    {
                    if(TenSach[i]>='a'&&TenSach[i]<='z')
                       TenSach[i]-=32;
                    }
                    cout<<"\n\t\tNhap ten tac gia : ";
                    cin.getline(TenTacGia,50);
                    cout<<"\n\t\tNhap ten nha xuat ban : ";
                    cin.getline(ID1,50);
                    cout<<"\n\t\tNhap ma sach : ";
                    cin.getline(ID,20);
                    cout<<"\n\t\tNhap gia sach : ";
                    cin>>p;
                    cout<<"\n\t\tNhap so luong : ";
                    cin>>q;
}
void Lib::show(int i)
{
    cout<<"\n\t\tTen Sach : "<<TenSach<<endl;
    cout<<"\n\t\tNhap ten tac gia : "<<TenTacGia<<endl;
    cout<<"\n\t\tID : "<<ID<<endl;
    cout<<"\n\t\tNha Xuat Ban : "<<ID1<<endl;
    if(i==2)
    {
        cout<<"\n\t\tGia sach : "<<p<<endl;
        cout<<"\n\t\tSo luong : "<<q<<endl;
    }
}
  void Lib::DSsach(int i)
  {
                int b,r=0;
                system("cls");
                b=branch(i);
                system("cls");
                ifstream intf("TTSach.txt",ios::binary);
                if(!intf)
                    cout<<"\n\t\tKo tim thay Data.";
                else
                {
                    cout<<"\n\t    ************ DS Sach ************ \n\n";
                    intf.read((char*)this,sizeof(*this));
                while(!intf.eof())
                {
                    if(b==B)
                    {
                        if(q==0 && i==1)
                        {

                        }
                        else
                            {
                                r++;
                                cout<<"\n\t\t********** "<<r<<". ********** \n";
                                show(i);
                            }
                    }
                    intf.read((char*)this,sizeof(*this));
                }
                }
                cout<<"\n\t\tNhap phim de tiep tuc.....";
                getch();
                system("cls");
                if(i==1)
                    SV();
                else
                    QuanLy();
    }
  void Lib::modify()
  {
    char ch,st1[100];
    int i=0,b,cont=0;
    system("cls");
    cout<<"\n\t\t>>Vui long chon mot lua chon :-\n";
    cout<<"\n\t\t1.Chinh sua sach hien tai\n\n\t\t2.Them sach moi\n\n\t\t3.Xoa sach\n\n\t\t4.Quay lai\n";
    cout<<"\n\n\t\tNhap lua chon : ";
    cin>>i;
    if(i==1)
    {
                    system("cls");
                    b=branch(2);
                    ifstream intf1("TTSach.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\n\t\tKo tim thay thong tin\n";
                        cout<<"\n\t\tAn phim bat ky de tiep tuc.....";
                        getch();
                        system("cls");
                        QuanLy();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\n\t\tVui long chon mot lua chon :-\n";
                        cout<<"\n\t\t1.Tim kiem theo ten\n\n\t\t2.Tim kiem theo ID\n";
                        cout<<"\n\t\tNhap lua chon cua ban : ";
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\n\t\tNhap ten sach : ";
                                cin.getline(st1,100);
                                system("cls");
                                fstream intf("TTSach.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&TenSach[i]!='\0'&&st1[i]!='\0'&&(st1[i]==TenSach[i]||st1[i]==TenSach[i]+32);i++);
                                        if(TenSach[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                getdata();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                                     intf.read((char*)this,sizeof(*this));
                                    }
                                    intf.close();
                            }
                        else if(i==2)
                        {
                                cout<<"\n\t\tNhap ID Sach : ";
                                cin.getline(ID,100);
                                system("cls");
                                fstream intf("TTSach.txt",ios::in|ios::out|ios::ate|ios::binary);
                                intf.seekg(0);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&ID1[i]!='\0'&&ID[i]!='\0'&&ID[i]==ID1[i];i++);
                                        if(ID1[i]=='\0'&&ID[i]=='\0')
                                            {
                                                cont++;
                                                getdata();
                                                intf.seekp(intf.tellp()-sizeof(*this));
                                                intf.write((char*)this,sizeof(*this));
                                                break;
                                            }
                                        intf.read((char*)this,sizeof(*this));
                                    }

                                intf.close();
                        }
                        else
                        {
                            cout<<"\n\t\tNhap sai.....:(\n";
                            cout<<"\n\t\tAn phim de tiep tuc.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        if(cont==0)
                        {
                            cout<<"\n\t\tKo tim thay sach.\n";
                            cout<<"\n\t\tAn phim de tiep tuc.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        else
                            cout<<"\n\t\tCap nhat thanh cong.\n";


    }
    else if(i==2)
    {
                    system("cls");
                    B=branch(2);
                    system("cls");
                    getdata();
                    ofstream outf("TTSach.txt",ios::app|ios::binary);
                    outf.write((char*)this,sizeof(*this));
                    outf.close();
                    cout<<"\n\t\tDa nhap them sach.\n";
    }
    else if(i==3)
    {
                    system("cls");
                    b=branch(2);
                    ifstream intf1("TTSach.txt",ios::binary);
                    if(!intf1)
                    {
                        cout<<"\n\t\tKo tim thay file\n";
                        cout<<"\n\t\tAn phim de tiep tuc.....";
                        getch();
                        intf1.close();
                        system("cls");
                        QuanLy();
                    }
                        intf1.close();
                        system("cls");
                        cout<<"\n\t\tVui long chon lua chon sau day de xoa sach-\n";
                        cout<<"\n\t\t1.Theo ten\n\n\t\t2.Theo ID\n";
                        cout<<"\n\t\tChon : ";
                        cin>>i;
                        fflush(stdin);
                        if(i==1)
                            {
                                system("cls");
                                cout<<"\n\t\tNhap ten sach : ";
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("TTSach.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&TenSach[i]!='\0'&&st1[i]!='\0'&&(st1[i]==TenSach[i]||st1[i]==TenSach[i]+32);i++);
                                        if(TenSach[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));

                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }

                    intf.close();
                    outf.close();
                    remove("TTSach.txt");
                    rename("temp.txt","TTSach.txt");
                            }
                        else if(i==2)
                        {
                                cout<<"\n\t\tChon ID sach : ";
                                cin.getline(st1,100);
                                ofstream outf("temp.txt",ios::app|ios::binary);
                                ifstream intf("TTSach.txt",ios::binary);
                                intf.read((char*)this,sizeof(*this));
                                while(!intf.eof())
                                    {
                                        for(i=0;b==B&&ID1[i]!='\0'&&st1[i]!='\0'&&st1[i]==ID1[i];i++);
                                        if(ID1[i]=='\0'&&st1[i]=='\0')
                                            {
                                                cont++;
                                                intf.read((char*)this,sizeof(*this));
                                            }
                                        else
                                        {
                                        outf.write((char*)this,sizeof(*this));
                                        intf.read((char*)this,sizeof(*this));
                                        }
                                    }
                    outf.close();
                    intf.close();
                    remove("TTSach.txt");
                    rename("temp.txt","TTSach.txt");
                        }
                        else
                        {
                            cout<<"\n\t\tNhap Sai.....:(\n";
                            cout<<"\n\t\tAn phim bat ki de tiep tuc.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        if(cont==0)
                        {
                            cout<<"\n\t\tKo tim thay sach.\n";
                            cout<<"\n\t\tNhan phim bat ky de tiep tuc.....";
                            getch();
                            system("cls");
                            modify();
                        }
                        else
                            cout<<"\n\t\tXoa thanh cong.\n";

    }
    else if(i==4)
    {
    system("cls");
    QuanLy();
    }
    else
    {
    cout<<"\n\t\tNhap sai.\n";
    cout<<"\n\t\tNhan phim bat ky de tiep tuc.....";
    getch();
    system("cls");
    modify();
    }
    cout<<"\n\t\tNhan phim bat ky de tiep tuc.....";
    getch();
    system("cls");
    QuanLy();

  }
  int Lib::branch(int x)
  {
      int i;
      cout<<"\n\t\t>>Vui long chon the loai :-\n";
      cout<<"\n\t\t1.Code\n\n\t\t2.Hoc May\n\n\t\t3.algorithm\n\n\t\t4.Triet\n\n\t\t5.Engineer\n\n\t\t6.1st year book\n\n\t\t7.Go to menu\n";
      cout<<"\n\t\tEnter youur choice : ";
      cin>>i;
      switch(i)
      {
          case 1: return 1;
                  break;
          case 2: return 2;
                  break;
          case 3: return 3;
                  break;
          case 4: return 4;
                  break;
          case 5: return 5;
                  break;
          case 6: return 6;
                  break;
          case 7: system("cls");
                  if(x==1)
                  SV();
                  else
                    QuanLy();
          default : cout<<"\n\t\tVui long chon lai :(";
                    getch();
                    system("cls");
                    branch(x);
        }
  }
  void Lib::see(int x)
  {
      int i,b,cont=0;
      char ch[100];
      system("cls");
      b=branch(x);
      ifstream intf("TTSach.txt",ios::binary);
        if(!intf)
        {
            cout<<"\n\t\tKo tim thay file.\n";
            cout<<"\n\t\t->Nhan phim bat ky de tiep tuc.....";
            getch();
            system("cls");
            if(x==1)
            SV();
            else
            QuanLy();
        }

      system("cls");
      cout<<"\n\t\tChon mot lua chon sau de tim sach :-\n";
      cout<<"\n\t\t1.Theo Ten\n\n\t\t2.Theo ID\n";
      cout<<"\n\t\tNhap lua chon : ";
      cin>>i;
      fflush(stdin);
      intf.read((char*)this,sizeof(*this));
      if(i==1)
      {
          cout<<"\n\t\tNhap ten sach : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
            for(i=0;b==B&&q!=0&&TenSach[i]!='\0'&&ch[i]!='\0'&&(ch[i]==TenSach[i]||ch[i]==TenSach[i]+32);i++);
            if(TenSach[i]=='\0'&&ch[i]=='\0')
                {
                        cout<<"\n\t\tKo tim thay sach :-\n";
                        show(x);
                        cont++;
                        break;
                }
             intf.read((char*)this,sizeof(*this));
          }
      }
          else if(i==2)
          {
          cout<<"\n\t\tNhap ID sach : ";
          cin.getline(ch,100);
          system("cls");
          while(!intf.eof())
          {
              for(i=0;b==B&&q!=0&&ID1[i]!='\0'&&ch[i]!='\0'&&ch[i]==ID1[i];i++);
              if(ID1[i]=='\0'&&ch[i]=='\0')
                {
                            cout<<"\n\t\tKo tim thay sach :-\n";
                            show(x);
                            cont++;
                            break;
                }
               intf.read((char*)this,sizeof(*this));
          }

          }
          else
          {
             cont++;
             cout<<"\n\t\tVui long chon lai :(  ";
             getch();
             system("cls");
             see(x);
          }
          intf.close();
          if(cont==0)
              cout<<"\n\t\tSach nay hien khong con :( \n";

    cout<<"\n\t\tNhap phim de tiep tuc.....";
    getch();
    system("cls");
    if(x==1)
    SV();
    else
    QuanLy();


  }
void Lib::issue()
{
    char st[50],st1[20];
    int b,i,j,d,m,y,dd,mm,yy,cont=0;
    system("cls");
    cout<<"\n\t\t->Chon mot lua chon sau :-\n";
    cout<<"\n\t\t1.Sach hien tai muon\n\n\t\t2.Xem thong tin sach muon\n\n\t\t3.Tim kiem sinh vien dang muon sach\n\n\t\t4.Muon lai sach\n\n\t\t5.Tra Sach\n\n\t\t6.Quay lai menu\n\n\t\tNhap lua chon : ";
    cin>>i;
    fflush(stdin);
    if(i==1)
    {
    system("cls");
    b=branch(2);
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Nhap thong tin sach:-\n";
    cout<<"\n\t\tTen sach : ";
    cin.getline(TenSach,100);
    cout<<"\n\t\tID : ";
    cin.getline(ID,20);
    //strcpy(st,sc);
    der(ID1,b,1);
    cout<<"\n\t\tTen Sinh Vien : ";
    cin.getline(TenTacGia,100);
    cout<<"\n\t\tID SV : ";
    cin.getline(ID,20);
    cout<<"\n\t\tNhap ngay : ";
    cin>>q>>B>>p;
    ofstream outf("TTSV.txt",ios::binary|ios::app);
    outf.write((char*)this,sizeof(*this));
    outf.close();
    cout<<"\n\n\t\tMuon Thanh Cong.\n";
    }
    else if(i==2)
    {
    ifstream intf("TTSV.txt",ios::binary);
    system("cls");
    cout<<"\n\t\t->Thong tin :-\n";
    intf.read((char*)this,sizeof(*this));
    i=0;
    while(!intf.eof())
    {
    i++;
    cout<<"\n\t\t********** "<<i<<". ********** \n";
    cout<<"\n\t\tTen SV : "<<TenTacGia<<"\n\t\t"<<"ID SV : "<<ID<<"\n\t\t"<<"Ten sach : "<<TenSach<<"\n\t\t"<<"ID Sach : "<<ID1<<"\n\t\t"<<"Ngay Muon : "<<q<<"/"<<B<<"/"<<p<<"\n";
    intf.read((char*)this,sizeof(*this));
    }
    intf.close();
    }
    else if(i==3)
    {
        system("cls");
        fflush(stdin);
        cout<<"\n\t\t->Nhap thong tin SV :-\n";
        cout<<"\n\n\t\tTen Sinh Vien : ";
        cin.getline(st,50);
        cout<<"\n\n\t\tID Sinh Vien: ";
        cin.getline(st1,20);
        system("cls");
        ifstream intf("TTSV.txt",ios::binary);
        intf.read((char*)this,sizeof(*this));
        cont=0;
        while(!intf.eof())
        {
              for(i=0;ID[i]!='\0'&&st1[i]!='\0'&&st1[i]==ID[i];i++);
              if(ID[i]=='\0'&&st1[i]=='\0')
              {
                  cont++;
                  if(cont==1)
                  {
                      cout<<"\n\t\t->Thong tin Sinh Vien :-\n";
                      cout<<"\n\t\tTen Sinh Vien : "<<TenTacGia;
                      cout<<"\n\t\tID Sinh Vien : "<<ID;
                  }
                  cout<<"\n\n\t\t******* "<<cont<<". Thong tin sach *******\n";
                  cout<<"\n\t\tTen Sach : "<<TenSach;
                  cout<<"\n\t\tID Sach : "<<ID;
                  cout<<"\n\t\tNgay : "<<q<<"/"<<B<<"/"<<p<<"\n";
              }
                      intf.read((char*)this,sizeof(*this));

        }
        intf.close();
        if(cont==0)
            cout<<"\n\t\tKo tim thay du lieu.";
    }
    else if(i==4)
    {
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Vui long nhap thong tin :-\n";
    cout<<"\n\n\t\tID Sinh Vien : ";
    cin.getline(st,50);
    cout<<"\n\t\tID Sach : ";
    cin.getline(st1,20);
    fstream intf("TTSV.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
        {
            for(i=0;ID1[i]!='\0'&&st1[i]!='\0'&&st1[i]==ID1[i];i++);
            for(j=0;ID[j]!='\0'&&st[j]!='\0'&&st[j]==ID[j];j++);
            if(ID1[i]=='\0'&&ID[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0')
                {
                    d=q;
                    m=B;
                    y=p;
                    cout<<"\n\t\tNhap ngay tra moi : ";
                    cin>>q>>B>>p;
                    fine(d,m,y,q,B,p); //fn1
                    intf.seekp(intf.tellp()-sizeof(*this)); //fn3
                    intf.write((char*)this,sizeof(*this)); //fn5
                    cout<<"\n\n\t\tMuon lai thanh cong."; //fn3
                    break;
                }
                   intf.read((char*)this,sizeof(*this));
        }
        intf.close();
    }
    else if(i==5)
    {
    system("cls");
    b=branch(2);
    system("cls");
    fflush(stdin);
    cout<<"\n\t\t->Vui long nhap thong tin :-\n";
    cout<<"\n\t\tID Sach : ";
    cin.getline(st1,20);
    der(st1,b,2);
    cout<<"\n\n\t\tID Sinh Vien : ";
    cin.getline(st,20);
    cout<<"\n\t\tNhap ngay hien tai : ";
    cin>>d>>m>>y;
    ofstream outf("temp.txt",ios::app|ios::binary);
    ifstream intf("TTSV.txt",ios::binary);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
        {
            for(i=0;ID1[i]!='\0'&&st1[i]!='\0'&&st1[i]==ID1[i];i++);
            for(j=0;ID[j]!='\0'&&st[j]!='\0'&&st[j]==ID[j];j++);
            if(ID1[i]=='\0'&&ID[j]=='\0'&&st[j]=='\0'&&st1[i]=='\0'&&cont==0)
                {
                    cont++;
                    intf.read((char*)this,sizeof(*this));
                    fine(q,B,p,d,m,y);
                    cout<<"\n\t\tTra sach thanh cong.";
                }
            else
                {
                    outf.write((char*)this,sizeof(*this));
                    intf.read((char*)this,sizeof(*this));
                }
        }

    intf.close();
    outf.close();
    getch();
    remove("TTSV.txt");
    rename("temp.txt","TTSV.txt");
    }
    else if(i==6)
    {
    system("cls");
    QuanLy();
    }
    else
        cout<<"\n\t\tNhap Sai.\n";

    cout<<"\n\n\t\tAn phim de tiep tuc.....";
    getch();
    system("cls");
    QuanLy();
}
void Lib::fine(int d,int m,int y,int dd,int mm,int yy)
{
    long int n1,n2;
    int years,l,i;
    const int monthDays[12] = {31, 28, 31, 30, 31, 30,31, 31, 30, 31, 30, 31};
    n1 = y*365 + d;
    for (i=0; i<m - 1; i++)
        n1 += monthDays[i]; 
    years = y;
    if (m <= 2)
    years--;
    l= years / 4 - years / 100 + years / 400;
    n1 += l;
    n2 = yy*365 + dd;
    for (i=0; i<mm - 1; i++)
        n2 += monthDays[i];
    years = yy;
    if (m <= 2)
    years--;
    l= years / 4 - years / 100 + years / 400;
    n2 += l;
    n1=n2-n1;
    n2=n1-15;
    if(n2>0)
    cout<<"\n\t\tTong Phi la : "<<n2;
    
}
void Lib::der(char st[],int b,int x)
{
    int i,cont=0;
    fstream intf("TTSach.txt",ios::in|ios::out|ios::ate|ios::binary);
    intf.seekg(0);
    intf.read((char*)this,sizeof(*this));
    while(!intf.eof())
    {
        for(i=0;b==B&&ID1[i]!='\0'&&st[i]!='\0'&&st[i]==ID1[i];i++);
        if(ID1[i]=='\0'&&st[i]=='\0')
        {
            cont++;
            if(x==1)
            {
                q--;
            }
            else
            {
                q++;
            }
            intf.seekp(intf.tellp()-sizeof(*this));
            intf.write((char*)this,sizeof(*this));
            break;
        }
        intf.read((char*)this,sizeof(*this));
    }
    if(cont==0)
    {
        cout<<"\n\t\tKo tim thay sach.\n";
        cout<<"\n\n\t\tNhap phim bat ki de tiep tuc.....";
        getch();
        system("cls");
        issue();
    }
    intf.close();
}
void Lib::get()
{
   int i;
        cout<<"\n\t*********** Quan Ly Thu Vien ***********\n"<<"\n\t\t\t   Group 17\n";
        cout<<"\n\t\t>>Login \n";
        cout<<"\n\t\t1.Sinh vien\n\n\t\t2.Quan ly thu vien\n\n\t\t3.Thoat\n";
        cout<<"\n\t\tNhap lua chon : ";
        cin>>i;
        if(i==1)
        {
            system("cls");
            SV();
        }
        else if(i==2)
            pass();

        else if(i==3)
            exit(0);
        else
        {
            cout<<"\n\t\tChon lai :<";
            getch();
            system("CLS");
           get();
        }
}
void Lib::SV()
{
    int i;
        cout<<"\n\t************ Chao mung SV ************\n";
        cout<<"\n\t\t>>Chon lua chon sau:\n";
        cout<<"\n\t\t1.Xem Ds Sach\n\n\t\t2.Tim kiem sach\n\n\t\t3.Quay lai menu chinh\n\n\t\t4.Thoat\n";
        cout<<"\n\t\tNhap lua chon : ";
        cin>>i;
            if(i==1)
                DSsach(1);
            else if(i==2)
                see(1);
            else if(i==3)
            {
                system("cls");
                get();
            }
            else if(i==4)
                exit(0);
            else
            {
                cout<<"\n\t\tChon lai :<";
                getch();
                system("cls");
                SV();
            }
}
void Lib::pass()
{
    int i=0;
    char ch,st[21],ch1[21]={"pass"};
    cout<<"\n\t\tNhap Password : ";
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream inf("password.txt");
    inf>>ch1;
    inf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        QuanLy();
    }
    else
    {
        cout<<"\n\n\t\tSai Password.\n\n\t\tVui long thu lai.....\n";
        getch();
        system("cls");
        get();
    }
}
void Lib::QuanLy()
{
    int i;
        cout<<"\n\t************ Quan Ly ************\n";
        cout<<"\n\t\t>>Chon lua chon Sau:\n";
        cout<<"\n\t\t1.Xem ds Sach\n\n\t\t2.Tim kiem sach\n\n\t\t3.Thay doi/them sach\n\n\t\t4.Muon sach\n\n\t\t5.Quay lai menu chinh\n\n\t\t6.Thay doi mk\n\n\t\t7.Thoat\n";
        cout<<"\n\t\tNhap lua chon : ";
        cin>>i;
        switch(i)
        {
            case 1:DSsach(2);
                     break;
            case 2:see(2);
                     break;
            case 3:modify();
                     break;
            case 4:issue();
                     break;
            case 5:system("cls");
                     get();
                     break;
            case 6:password();
                    break;
            case 7:exit(0);
            default:cout<<"\n\t\tVui long chon lai :<";
            getch();
            system("cls");
            QuanLy();
        }
}
void Lib::password()
{
    int i=0,j=0;
    char ch,st[21],ch1[21]={"pass"};
    system("cls");
    cout<<"\n\n\t\tNhap lai mat khau cu : ";
    while(1)
    {
    ch=getch();
    if(ch==13)
    {
        st[i]='\0';
        break;
    }
    else if(ch==8&&i>0)
    {
        i--;
        cout<<"\b \b";
    }
    else
    {
    cout<<"*";
    st[i]=ch;
    i++;
    }
    }
    ifstream intf("password.txt");
    intf>>ch1;
    intf.close();
    for(i=0;st[i]==ch1[i]&&st[i]!='\0'&&ch1[i]!='\0';i++);
    if(st[i]=='\0'&&ch1[i]=='\0')
    {
        system("cls");
        cout<<"\n\t**MK moi phai it hon 20 ki tu & ko dc cach**\n\n";
        cout<<"\n\t\tNhap mat khau moi : ";
        fflush(stdin);
        i=0;
        while(1)
        {
        j++;
        ch=getch();
        if(ch==13)
        {
            for(i=0;st[i]!=' '&&st[i]!='\0';i++);
            if(j>20 || st[i]==' ')
            {
                cout<<"\n\n\t\tMk moi hon 20 hoac co cach.Failier \n\n\t\tNhap phim de thu lai.....";
                getch();
                system("cls");
                password();
                QuanLy();
            }
            st[i]='\0';
            break;
        }
        else if(ch==8&&i>0)
        {
            i--;
            cout<<"\b \b";
        }
        else
        {
        cout<<"*";
        st[i]=ch;
        i++;
        }
        }
        ofstream outf("password.txt");
        outf<<st;
        outf.close();
        cout<<"\n\n\t\tMat khau cua ban thay doi thanh cong.";
        cout<<"\n\t\tAn phim de tiep tuc......";
        getch();
        system("cls");
        QuanLy();
    }
    else
    {
        cout<<"\n\n\t\tMk sai.....\n";
        cout<<"\n\t\tChon 1 de thu lai hoac 2 de quay lai menu";
        cin>>i;
        if(i==1)
        {
        system("cls");
        password();
        }
        else
        {
            system("cls");
            QuanLy();
        }
    }
}
int main()
{
    Lib obj;
    obj.get();
    getch();
    return 0;
}
