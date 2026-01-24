#include "../header/alarmSet.h"

void alarmInit(Alarm* alarm) {
    alarm->size = 0;
}

bool containsId(Alarm* alarmSet, Event* e) {
    for (int i = 0; i < alarmSet->size; i++) {
        if ( e->_Id == alarmSet->sensorId[i]) {
            return true;
        }
    }
    return false;
}

bool addAlarm(Alarm *alarmSet, Event *e) {
    if (!containsId(alarmSet, e) && alarmSet->size < MAX_ALARMS) {
        alarmSet->sensorId[alarmSet->size] = e->_Id;
        alarmSet->size++;
        return true;
    }

    return false;
}

static int findAlarmIndex(Alarm* alarmSet,Event *e) {
    for (int i = 0; i < alarmSet->size; i++) {
        if (e->_Id == alarmSet->sensorId[i]) { return i;}
    }
    return -1;
}

bool removeAlarm(Alarm *alarmSet, Event *e) {
    if (alarmSet->size == 0){return false;}
    int indexToRemove = findAlarmIndex(alarmSet,e);
    if (indexToRemove == -1){return false;}
    alarmSet->sensorId[indexToRemove] = alarmSet->sensorId[alarmSet->size -1];
    alarmSet->size--;
    return true;
}

