#include <iostream>

namespace ilrd143
{
    class MachinesAlarm
    {
    public:
        enum Severity
        {
            MINOR,
            MAJOR
        };

        struct Machine
        {
            std::string name;
            int minAlarmValue;
            Severity severity;
        };

        struct Alarm 
        {
            std::string name;
            int alarmValue;
            time_t time;
            Severity severity;
        };

    private:
    };

}