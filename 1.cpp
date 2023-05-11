#include <iostream>
using std::cout;
using std::string;

enum class WriteType {
  Full,
  AlmostFull,
  ABit
};

enum class Status{
  OnTheGround,
  UpOnTheAir,
  DownOnTheAir,
  OnThePic
};

enum class Tmp{
  Ft = 15,
  Sc, // Это значение 16
  Thr, // Это 17
  Ct = 15*15*15*15, // А это честный 15^4 (50625)
  Pt // А это 15^4 + 1
};

const int MY_WEIGHT = 55;

class Myaschic{
public:
  int weight;
  Status st;
  Myaschic(int _wth, Status _st = Status::UpOnTheAir) : weight(_wth), st(_st){}

  string get_string_status(){
    switch (st)
    {
    case Status::DownOnTheAir :
      return "падает";
      break;
    case Status::UpOnTheAir :
      return "взлетает";
      break;
    case Status::OnThePic :
      return "в самом рассвете сил";
      break;
    case Status::OnTheGround :
      return "лежит";
      break;
    }
    return "не существует";
  }

  void print(WriteType tp){
    cout << "Твой мячик сейчас ";
    switch (tp)
    {
    case WriteType::Full :
      cout << "существует";
      break;
    case WriteType::AlmostFull :
      cout << get_string_status() << " и весит " << weight;
      break;
    case WriteType::ABit :
      cout << get_string_status() << " и весит " << (weight > MY_WEIGHT ? "очень очень много" : "чуть чуть");
      break;
    }
    cout << std::endl;
    return;
  }
};

// using enum WriteType; // Так можно начиная с C++20, 
// и так не надо писать EnumName:: перед каждым нужным пар-ром
// Благо лечиться копипастом этого самого EnumName::

int main(){
  Myaschic mt(40), mc(55, Status::OnThePic), mb(100, Status::DownOnTheAir);
  mt.print(WriteType::Full); // Твой мячик сейчас существует
  mc.print(WriteType::AlmostFull); // Твой мячик сейчас в самом рассвете сил и весит 55
  mb.print(WriteType::ABit); // Твой мячик сейчас падает и весит очень очень много

  cout << static_cast<int>(Tmp::Pt); // 50626
}
