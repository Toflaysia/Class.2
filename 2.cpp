
#include <iostream>
#include <string>

using namespace std;

class Time {
public:
    int hours;
    int minutes;
    int seconds;


    Time() {                                       //конструктор по умолчанию
        this->hours = 0;
        this->minutes = 0;
        this->seconds = 0;
    };

    void Time_check(int& hours, int& minutes, int& seconds) {                              //проверка времени
        if (seconds >= 61) {
            minutes += seconds / 60;
            seconds = seconds % 60;
        }
        if (seconds <= -1) {
            minutes += (seconds / 60);
            if (seconds % 60 == 0) {
                seconds = 0;
            }
            else {
                minutes = minutes - 1;
                seconds = 60 + seconds % 60;
            }
        }
        if (minutes >= 61) {
            hours += minutes / 60;
            minutes = minutes % 60;
        }
        if (minutes <= -1) {
            hours += (minutes / 60);
            if (minutes % 60 == 0) {
                minutes = 0;
            }
            else {
                hours = hours - 1;
                minutes = 60 + minutes % 60;
            }
        }
        if (hours >= 25) {
            hours = hours % 24;
        }
        if (hours <= -1) {
            cout << "Некорректные данные" << endl;
            cout << "Вводится значение по умолчанию - 0 часов" << endl;
            hours = 0;
        }
    }

    void set_Time(int hours, int minutes, int seconds) {              //ф-ция для изменения полей часов, минут, секунд

        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }

    Time(int hours, int minutes, int seconds) {    //конструктор по добавлению новых объектов

        Time_check(hours, minutes, seconds);

        this->hours = hours;
        this->minutes = minutes;
        this->seconds = seconds;
    }

    Time operator + (const Time& a) {                            //перегрузка оператора +
        int new_hours;
        int new_minutes;
        int new_seconds;
        new_hours = a.hours + this->hours;       
        new_minutes = a.minutes + this->minutes;  
        new_seconds = a.seconds + this->seconds; 

        Time new_time(new_hours, new_minutes, new_seconds);      //объект, в котором находится новое время
        return new_time;               
    }

    Time operator - (const Time& a) {                            //перегрузка оператора - 
        int new_hours;
        int new_minutes;
        int new_seconds;
        new_hours = this->hours - a.hours;
        new_minutes = this->minutes - a.minutes;
        new_seconds = this->seconds - a.seconds;

        Time new_time(new_hours, new_minutes, new_seconds);       
        return new_time;
    }

    Time& operator += (const Time& a) {
        // i+=2 --> i=i+2
        this->hours = this->hours + a.hours;
        this->minutes = this->minutes + a.minutes;
        this->seconds = this->seconds + a.seconds;
        Time_check(this->hours, this->minutes, this->seconds);  //вызываю функцию проверки времени

        return *this;                                                           //возвращаю ССЫЛКУ на этот самый объект
    }

    Time& operator -= (const Time& a) {
        this->hours = this->hours - a.hours;
        this->minutes = this->minutes - a.minutes;
        this->seconds = this->seconds - a.seconds;
        Time_check(this->hours, this->minutes, this->seconds);

        return *this;                                             //возвращаю ССЫЛКУ на этот самый объект
    }

    bool operator > (const Time& a) {                            // сравнение больше
        if (this->hours > a.hours) {
            return true;
        }
        if (this->hours < a.hours) {
            return false;
        }
        if (this->minutes > a.minutes) {
            return true;
        }
        if (this->minutes < a.minutes) {
            return false;
        }
        if (this->seconds > a.seconds) {
            return true;
        }
        if (this->seconds < a.seconds) {
            return false;
        }
    }

    bool operator < (const Time& a) {                           //сравнение меньше
        if (this->hours < a.hours) {
            return true;
        }
        if (this->hours > a.hours) {
            return false;
        }
        if (this->minutes < a.minutes) {
            return true;
        }
        if (this->minutes > a.minutes) {
            return false;
        }
        if (this->seconds < a.seconds) {
            return true;
        }
        if (this->seconds > a.seconds) {
            return false;
        }
    }
    bool operator == (const Time& a) {
        if (this->hours == a.hours && this->minutes == a.minutes && this->seconds == a.seconds) {                //равенство
            return true;
        }
        if (this->hours != a.hours || this->minutes != a.minutes || this->seconds != a.seconds) {
            return false;
        }
    }
    bool operator != (const Time& a) {                                                                            //неравенство
        if (this->hours != a.hours || this->minutes != a.minutes || this->seconds != a.seconds) {
            return true;
        }
        else{
            return false;
        }
    }
    void convert() {
        int hours_12 = this->hours % 12;
        string half_day;
        if (this->hours / 12 == 0) {
            half_day = "am";
        }
        else {
            half_day = "pm";
        }
        cout << "Время в 12-часовом формате: " << hours_12 << half_day << ":" << this -> minutes << ":" << this -> seconds<< endl;
    }
};

        
ostream& operator << (ostream& stream, const Time& a) {                  //перегрузка оператора вывода
    stream << a.hours << ":" << a.minutes << ":" << a.seconds;

    return stream;
}

istream& operator >> (istream& in, Time& a) {                  //перегрузка оператора ввода
    int hours;
    int minutes;
    int seconds;
    in >> hours >> minutes >> seconds;
    a.set_Time(hours, minutes, seconds);

    return in;
}


int main()
{
    setlocale(LC_ALL, "RU");
    Time t(12, 10, 0);
    Time a(8, 07, 15);
    Time c = t + a;
    Time d = t - a;
    t += a; 
    a -= t;
    a.convert();
    cout << c.hours << ":" << c.minutes << ":" << c.seconds << endl;
    cout << d.hours << ":" << d.minutes << ":" << d.seconds << endl;
    cout << t.hours << ":" << t.minutes << ":" << t.seconds << endl;
    cout << a.hours << ":" << a.minutes << ":" << a.seconds << endl;
    cout << (a > t) << endl;
    cout << (a < t) << endl;
    cout << (a == t) << endl;
    cout << (a != t) << endl;
    cout << a << endl; 
    cin >> a;
    cout << a;

    return 0;
}