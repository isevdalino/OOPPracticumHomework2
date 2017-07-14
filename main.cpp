#include <iostream>
#include <cstring>
#include <vector>

using namespace std;
//Ex1
class Device{
  protected:
  double price;
  char* producer;
  public:
  Device(double price=0,char* producer=""){
    this->price=price;
    this->producer=new char[strlen(producer)+1];
    strcpy(this->producer,producer);
  }
  Device(const Device& other){
    this->price=other.getPrice();
    this->producer=new char[strlen(other.getProducer())+1];
    strcpy(this->producer,other.getProducer());
  }
  Device& operator=(const Device& other){
    if(this!=&other){
      delete [] producer;
      this->price=price;
      this->producer=new char[strlen(producer)+1];
      strcpy(this->producer,producer);
    }
    return *this;
  }
  ~Device(){
     delete [] producer;
   }
   double getPrice()const{
     return price;
   }
   char* getProducer()const{
     return producer;
   }
   void setPrice(double price){
     this->price=price;
   }
   void setProducer(char* producer){
     delete [] producer;
     this->producer=new char[strlen(producer)+1];
     strcpy(this->producer,producer);
   }
  virtual double rating(){
    return 0;
  };
};

class Printer:public Device{
  bool isItColorful;
  public:
  Printer(bool isItColorful=false){
    this->isItColorful=isItColorful;
  }
  Printer(const Printer& other){
    isItColorful=other.isItColorfulOrNot();
  }
  Printer& operator=(const Printer& other){
    if(this!=&other){
      isItColorful=other.isItColorfulOrNot();
    }
    return *this;
  }
  ~Printer(){
   }
  bool isItColorfulOrNot()const{
    return isItColorful;
  }
  void setColorfulOrNot(bool flag){
    isItColorful=flag;
  }
  virtual double rating(){
    if(isItColorful==true){
      return (this->getPrice()*this->getPrice())/2;
    }else{
      return this->getPrice()/2;
    }
  }
};

struct Resolution{
  int width;
  int height;
};

class Laptop:public Device{
  Resolution rez;
  int ram;
  public:
  Laptop(int w,int h,int ram){
    rez.width=w;
    rez.height=h;
    this->ram=ram;
  }
  Laptop(const Laptop& other){
    rez.width=other.getRez().width;
    rez.height=other.getRez().height;
    this->ram=other.getRam();
  }
  Laptop& operator=(const Laptop& other){
    if(this!=&other){
      rez.width=other.getRez().width;
      rez.height=other.getRez().height;
      this->ram=other.getRam();
    }
    return *this;
  }
  ~Laptop(){
   }
  void setRam(int ram){
    this->ram=ram;
  }
  int getRam()const{
    return ram;
  }
  void setRez(int w,int h){
    rez.width=w;
    rez.height=h;
  }
  Resolution getRez()const{
    return rez;
  }

  virtual double rating(){
    return (this->getPrice()+ram)/2;
  }
};

class PC:public Device{
  int HD;
  char* OS;
  int ram;
  public:
  PC(int HD,char* OS,int ram){
    this->HD=HD;
    this->ram=ram;
    this->OS=new char[strlen(OS)+1];
    strcpy(this->OS,OS);
  }
  PC(const PC& other){
    this->HD=other.getHD();
    this->ram=other.getRam();
    this->OS=new char[strlen(other.getOS())+1];
    strcpy(this->OS,other.getOS());
  }
  PC& operator=(const PC& other){
    if(this!=&other){
      delete [] OS;
      this->HD=other.getHD();
      this->ram=other.getRam();
      this->OS=new char[strlen(other.getOS())+1];
      strcpy(this->OS,other.getOS());
    }
    return *this;
  }
  ~PC(){
     delete [] OS;
   }
  void setRam(int ram){
    this->ram=ram;
  }
  int getRam()const{
    return ram;
  }
  int getHD()const{
    return HD;
  }
  void setHD(int HD){
    this->HD=HD;
  }
  char* getOS()const{
    return OS;
  }
  char* setOS(char* OS){
    delete [] OS;
    this->OS=new char[strlen(OS)+1];
    strcpy(this->OS,OS);
  }

  virtual double rating(){
    return (this->getPrice()+ram+HD)/2;
  }
};

//Ex2
class Ticket{
  protected:
  char* railHead;
  char* terminus;
  double price;
  public:
  Ticket(char* railHead="",char* terminus="",double price=0){
    this->railHead=new char[strlen(railHead)+1];
    strcpy(this->railHead,railHead);
    this->terminus=new char[strlen(terminus)+1];
    strcpy(this->terminus,terminus);
    this->price=price;
  }
  ~Ticket(){
    delete [] railHead;
    delete [] terminus;
   }
  Ticket(const Ticket& other){
    this->railHead=new char[strlen(other.getRailHead())+1];
    strcpy(this->railHead,other.getRailHead());
    this->terminus=new char[strlen(other.getTerminus())+1];
    strcpy(this->terminus,other.getTerminus());
    this->price=other.getPrice();
  }
  Ticket& operator=(const Ticket& other){
    if(this!=&other){
      delete [] railHead;
      delete [] terminus;
      this->railHead=new char[strlen(other.getRailHead())+1];
      strcpy(this->railHead,other.getRailHead());
      this->terminus=new char[strlen(other.getTerminus())+1];
      strcpy(this->terminus,other.getTerminus());
      this->price=other.getPrice();
    }
    return *this;
  }
  virtual double getPrice()const{
    return price;
  }
  char* getRailHead()const{
    return railHead;
  }
  char* getTerminus()const{
    return terminus;
  }
  virtual char* getType()const{
    return "Normal ticket";
  }
  virtual void setIsInGroup(bool isInGroup){
    return;
  }
};

class StudentsTicket:public Ticket{
  public:
  StudentsTicket(char* railHead="",char* terminus="",double price=0):Ticket(railHead,terminus,price){

  }
  StudentsTicket(const StudentsTicket& other):Ticket(other){

  }
  StudentsTicket& operator=(const StudentsTicket& other){
    if(this!=&other){
      Ticket::operator=(other);
    }
    return *this;
  }
  virtual char* getType()const{
    return "Student ticket";
  }
  virtual double getPrice()const{
    return price*0.5;
  }
  virtual void setIsInGroup(bool isInGroup){
    return;
  }
};

class GroupTicket:public Ticket{
  bool isInGroup;
  public:
  GroupTicket(char* railHead="",char* terminus="",double price=0,bool isInGroup=false):Ticket(railHead,terminus,price){
    this->isInGroup=isInGroup;
  }
  GroupTicket(const GroupTicket& other):Ticket(other){
    isInGroup=other.getIsInGroup();
  }
  GroupTicket& operator=(const GroupTicket& other){
    if(this!=&other){
      Ticket::operator=(other);
      isInGroup=other.getIsInGroup();
    }
    return *this;
  }
  virtual void setIsInGroup(bool isInGroup){
    this->isInGroup=isInGroup;
  }
  bool getIsInGroup()const{
    return isInGroup;
  }
  virtual char* getType()const{
    return "Group ticket";
  }
  virtual double getPrice()const{
    if(isInGroup){
    return price*0.3;
    }else{
    return price;
    }
  }
};

class Train{
  char* railHead;
  char* terminus;
  int numSeatsLeft;
  int numSeats;
  vector<Ticket*> tickets;
  public:
  Train(char* railHead="",char* terminus="",int numSeats=0){
    this->railHead=new char[strlen(railHead)+1];
    strcpy(this->railHead,railHead);
    this->terminus=new char[strlen(terminus)+1];
    strcpy(this->terminus,terminus);
    this->numSeatsLeft=numSeats;
    this->numSeats=numSeats;
  }
  Train(const Train& other){
    this->railHead=new char[strlen(other.getRailHead())+1];
    strcpy(this->railHead,other.getRailHead());
    this->terminus=new char[strlen(other.getTerminus())+1];
    strcpy(this->terminus,other.getTerminus());
    this->numSeatsLeft=other.getNumSeatsLeft();
    this->numSeats=other.getNumSeats();
  }
  Train& operator=(const Train& other){
    if(this!=&other){
      delete [] railHead;
      delete [] terminus;
      this->railHead=new char[strlen(other.getRailHead())+1];
      strcpy(this->railHead,other.getRailHead());
      this->terminus=new char[strlen(other.getTerminus())+1];
      strcpy(this->terminus,other.getTerminus());
      this->numSeatsLeft=other.getNumSeatsLeft();
      this->numSeats=other.getNumSeats();
    }
    return *this;
  }
  ~Train(){
     delete [] railHead;
     delete [] terminus;
     for(int i=0;i<tickets.size();i++){
        delete tickets[i];
     }
  }
  char* getRailHead()const{
    return railHead;
  }
  char* getTerminus()const{
    return terminus;
  }
  int getNumSeatsLeft()const{
    return numSeatsLeft;
  }
  int getNumSeats()const{
    return numSeats;
  }
  double getMoneyGathered()const{
    int count=0;
    for(int i=0;i<tickets.size();i++){
      count+=tickets[i]->getPrice();
    }
    return count;
  }
  friend class BDZ;
};

class BDZ{
  vector<Train> trains;
  public:
  BDZ(vector<Train> trains){
    this->trains=trains;
  }
  void sellTicket(char* railHead,char* terminus,char* type,double price){
    for(int i=0;i<trains.size();i++){
      if((strcmp(trains[i].getRailHead(),railHead)==0)&&(strcmp(trains[i].getTerminus(),terminus)==0)&&
         trains[i].getNumSeatsLeft()>0){
         if(strcmp(type,"Normal ticket")==0){
            trains[i].tickets.push_back(new Ticket(railHead,terminus,price));
            trains[i].numSeatsLeft--;
         }else if(strcmp(type,"Student ticket")==0){
           trains[i].tickets.push_back(new StudentsTicket(railHead,terminus,price));
           trains[i].numSeatsLeft--;
         }else if(strcmp(type,"Group ticket")==0){
           trains[i].tickets.push_back(new GroupTicket(railHead,terminus,price));
           int count=0;
           for(int j=0;j<trains[i].tickets.size();j++){
             if(strcmp(trains[i].tickets[j]->getType(),"Group ticket")==0){
                count++;
             }
           }
           if(count>=4){
             for(int j=0;j<trains[i].tickets.size();j++){
             if(strcmp(trains[i].tickets[j]->getType(),"Group ticket")==0){
               trains[i].tickets[j]->setIsInGroup(true);
             }
           }
           }
           trains[i].numSeatsLeft--;
         }
      }
    }
  }
  double getMoneyGatheredForTrain(int i){
    return trains[i].getMoneyGathered();
  }
};
int main()
{
    //Ex1
    Device* arr[3]={new Printer(true),new Laptop(1800,1500,1024),new PC(1024,"Windows",512)};
    double totalRating=0;
    cout<<"Ex1"<<endl;
    cout<<"Printer rating:"<<arr[0]->rating()<<endl;
    cout<<"Laptop rating:"<<arr[1]->rating()<<endl;
    cout<<"PC rating:"<<arr[2]->rating()<<endl;
    totalRating=arr[0]->rating()+arr[1]->rating()+arr[2]->rating();
    cout<<"The total rating of the devices is:"<<totalRating<<endl;
    cout<<endl;
    arr[0]->setPrice(1000);
    arr[1]->setPrice(2000);
    arr[2]->setPrice(3000);
    cout<<"Printer rating:"<<arr[0]->rating()<<endl;
    cout<<"Laptop rating:"<<arr[1]->rating()<<endl;
    cout<<"PC rating:"<<arr[2]->rating()<<endl;
    totalRating=arr[0]->rating()+arr[1]->rating()+arr[2]->rating();
    cout<<"The total rating of the devices is:"<<totalRating<<endl;
    cout<<"\nEx2"<<endl;
    //Creating a BDZ with 3 trains
    vector<Train> trains={Train("Sofia","Varna",5),Train("Sofia","Plovdiv",3),Train("Ruse","Varna",4)};
    BDZ bdz(trains);
    //Selling 6 student tickets from Sofia to Varna,but there are only 5 seats on the given train
    bdz.sellTicket("Sofia","Varna","Student ticket",300);
    bdz.sellTicket("Sofia","Varna","Student ticket",300);
    bdz.sellTicket("Sofia","Varna","Student ticket",300);
    bdz.sellTicket("Sofia","Varna","Student ticket",300);
    bdz.sellTicket("Sofia","Varna","Student ticket",300);
    bdz.sellTicket("Sofia","Varna","Student ticket",300);
    //Selling 1 normal ticket from Sofia to Plovdiv
    bdz.sellTicket("Sofia","Plovdiv","Normal ticket",300);
    cout<<"The train from Sofia to Varna has gathered:"<<bdz.getMoneyGatheredForTrain(0)<<endl;
    cout<<"The train from Sofia to Plovdiv has gathered:"<<bdz.getMoneyGatheredForTrain(1)<<endl;
    //Selling 3 group tickets from Ruse to Varna-not enough to form a group
    bdz.sellTicket("Ruse","Varna","Group ticket",300);
    bdz.sellTicket("Ruse","Varna","Group ticket",300);
    bdz.sellTicket("Ruse","Varna","Group ticket",300);
    //Selling a 4th group ticket from Ruse to Varna-now they are enough to form a group
    cout<<"The train from Ruse to Varna has gathered:"<<bdz.getMoneyGatheredForTrain(2)<<endl;
    bdz.sellTicket("Ruse","Varna","Group ticket",300);
    cout<<"The train from Ruse to Varna has gathered:"<<bdz.getMoneyGatheredForTrain(2)<<endl;
    return 0;
}
