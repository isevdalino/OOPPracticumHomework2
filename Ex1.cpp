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
