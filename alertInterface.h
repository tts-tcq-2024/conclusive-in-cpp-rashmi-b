#ifndef ALERT_INTERFACE_H
#define ALERT_INTERFACE_H

class IAlertInterface{
public:
    virtual std::string printBreachTypeInfo(std::string recipient) = 0;
};

class AlertInterface{
public:
    IAlertInterface *alertinterface;
    AlertInterface(IAlertInterface *alert) : alertinterface(alert){}
    ~AlertInterface()
    {
        delete this->alertinterface;
    }
    void outputAlert(std::string recipient){
        alertinterface->printBreachTypeInfo(recipient);
    }
};

class LowBreachType : public IAlertInterface{
public:
    std::string printBreachTypeInfo(std::string recipient){
        std::string emailContent = {"To: " +recipient};
        emailContent += " Alert! the temperature is too low\n";
        return emailContent;
    }
};

class HighBreachType: public IAlertInterface{
public:
    std::string printBreachTypeInfo(std::string recipient) {
        std::string emailContent = "To: " + recipient;
        emailContent += " Alert! the temperature is too high\n";
        return emailContent;
    }
};

class NormalBreachType: public IAlertInterface{
public:
    std::string printBreachTypeInfo(std::string recipient) {
        std::string emailContent = "To: " + recipient;
        emailContent += " Tsshe temperature is normal\n";
        return emailContent;
    }
};
#endif //ALERT_INTERFACE_H