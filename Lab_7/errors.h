#ifndef ERRORS_H
#define ERRORS_H

namespace ret {
enum erorrs {
        Ok                  =  0,   // ����
        ErrIO              = -1,    // �ਢ�襭� �᫮ ����⮪ ����� ������
        ErrSize           = -2,     // �ਢ�襭 ࠧ���
        ErrTrans         = -3,    // �訡�� �࠭���樨
    };
}
#endif // ERRORS_H
