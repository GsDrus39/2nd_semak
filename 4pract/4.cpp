#include <iostream>
#include <string>
#include "fstream"

class Device {
private:
    std::string name;
public:
    explicit Device(const std::string &name) {
        this->name = name;
    }

    void poll() {
        std::cout << name << std::endl;
    }
    
    std::string get_name(){
        return name;
    }
};

class Counter : public Device {
public:
    explicit Counter(const std::string &name) : Device(name) {};
    void poll() {
        std::cout << get_name() << std::endl;
        /* do something */
    };
};

class DiscreteSignal : public Device {
public:
    explicit DiscreteSignal(const std::string &name) : Device(name) {};
    void poll() {
        std::cout << get_name() << std::endl;
        /* do something */
    };
};

class Heating : public Device {
public:
    explicit Heating(const std::string &name) : Device(name) {};
    void poll() {
        std::cout << get_name() << std::endl;
        /* do something */
    };
};

std::string counters[] = {
        "Меркурий 230", "Нева МТ314", "Энергомера CE308"
};
std::string discreteSignals[] = {
        "Reallab NL-16HV", "Приборэлектро PRE-16", "Энергосервис ЭНМВ-1-24"
};
std::string heatings[] = {
        "Ouman S203", "Овен ТРМ232"
};

struct {
    Counter *counter = nullptr;
    DiscreteSignal *discreteSignal = nullptr;
    Heating *heating = nullptr;
} configuration;

int main() {
    setlocale(LC_ALL, "ru");
    std::ifstream devices("../config.txt");
    std::string currentDevice;
    while (getline(devices, currentDevice)) {
        int n = sizeof(counters) / sizeof(std::string);
        for (int i = 0; i < n; i++) {
            if (counters[i] == currentDevice) {
                Counter *counter = new Counter(currentDevice);
                configuration.counter = counter;
                configuration.counter->poll();
            }
        }
        n = sizeof(discreteSignals) / sizeof(std::string);
        for (int i = 0; i < n; i++) {
            if (discreteSignals[i] == currentDevice) {
                DiscreteSignal *discreteSignal = new DiscreteSignal(currentDevice);
                configuration.discreteSignal = discreteSignal;
                configuration.discreteSignal->poll();
            }
        }
        n = sizeof(heatings) / sizeof(std::string);
        for (int i = 0; i < n; i++) {
            if (heatings[i] == currentDevice) {
                Heating *heating = new Heating(currentDevice);
                configuration.heating = heating;
                configuration.heating->poll();
            }
        }
    }
}
