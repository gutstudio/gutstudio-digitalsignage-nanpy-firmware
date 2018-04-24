#include "cfg.h"

#if USE_FastLED

#include <Arduino.h>
#include <FastLED.h>
#include "FastLEDClass.h"
#include <stdlib.h>

const char* nanpy::FastLEDClass::get_firmware_id()
{
    return "FastLED";
}

nanpy::FastLEDClass::FastLEDClass(enum ledType, int dataPin, char colorOrder, struct leds, int numLEDs) {
    self.addLeds<ledType,dataPin,colorOrder>(leds, NUM_LEDS).setCorrection(TypicalLEDStrip);
	}

void nanpy::FastLEDClass::elaborate( MethodDescriptor* m ) {
    ObjectsManager<FastLED>::elaborate(m);

    if (strcmp(m->getName(),"new") == 0) {
        FastLED* fastled;
        fastled = new FastLED ();
        fastled->begin();
        v.insert(fastled);
        m->returns(v.getLastIndex());
    }

    if (strcmp(m->getName(), "show") == 0) {
        m->returns(v[m->getObjectId()]->show());
    }

    if (strcmp(m->getName(), "delay") == 0) {
        m->returns(v[m->getObjectId()]->delay(m->getInt(0)));
    }

    if (strcmp(m->getName(), "setBrightness") == 0) {
        m->returns(v[m->getObjectId()]->setBrightness(m->getInt(0)));
    }

    if (strcmp(m->getName(), "setCorrection") == 0) {
        m->returns(v[m->getObjectId()]->setCorrection(m->getInt(0)));
    }
};

#endif
