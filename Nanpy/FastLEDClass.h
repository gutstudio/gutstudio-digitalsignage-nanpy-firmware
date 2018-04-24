#ifndef FASTLED_CLASS
#define FASTLED_CLASS

#include "BaseClass.h"
#include "MethodDescriptor.h"

class FastLED;

namespace nanpy {
    class FastLED: public ObjectsManager<FastLED> {
        public:
            void elaborate( nanpy::MethodDescriptor* m );
            const char* get_firmware_id();
    };
}

#endif
