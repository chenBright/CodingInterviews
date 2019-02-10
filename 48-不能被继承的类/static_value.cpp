#include <iostream>

class SealedClass {
public:
    static SealedClass* GetInstance() {
        if (m_sc == NULL) {
            m_sc = new SealedClass();
        }

        return m_sc;
    }

    static void Destory() {
        if (m_sc != NULL) {
            delete m_sc;
        }
    }

private:
    static SealedClass  *m_sc;
    SealedClass() {}
    ~SealedClass(){}
};

SealedClass *SealedClass::m_sc = NULL;

class Base : public SealedClass {};