/****************************************************************************
** Resource object code
**
** Created by: The Resource Compiler for Qt version 5.12.3
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

static const unsigned char qt_resource_data[] = {
  // E:/VS2017/qt/Qt5Dev/chapter7/textFile/textFile/Resources/point.txt
  0x0,0x0,0x0,0x0,
  
  
};

static const unsigned char qt_resource_name[] = {
  // Resources
  0x0,0x9,
  0xa,0x6c,0x38,0x43,
  0x0,0x52,
  0x0,0x65,0x0,0x73,0x0,0x6f,0x0,0x75,0x0,0x72,0x0,0x63,0x0,0x65,0x0,0x73,
    // point.txt
  0x0,0x9,
  0x0,0x57,0xb5,0x34,
  0x0,0x70,
  0x0,0x6f,0x0,0x69,0x0,0x6e,0x0,0x74,0x0,0x2e,0x0,0x74,0x0,0x78,0x0,0x74,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/Resources
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x2,
0x0,0x0,0x0,0x0,0x0,0x0,0x0,0x0,
  // :/Resources/point.txt
  0x0,0x0,0x0,0x18,0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,
0x0,0x0,0x1,0x6e,0xf7,0xaf,0xc4,0x43,

};

#ifdef QT_NAMESPACE
#  define QT_RCC_PREPEND_NAMESPACE(name) ::QT_NAMESPACE::name
#  define QT_RCC_MANGLE_NAMESPACE0(x) x
#  define QT_RCC_MANGLE_NAMESPACE1(a, b) a##_##b
#  define QT_RCC_MANGLE_NAMESPACE2(a, b) QT_RCC_MANGLE_NAMESPACE1(a,b)
#  define QT_RCC_MANGLE_NAMESPACE(name) QT_RCC_MANGLE_NAMESPACE2( \
        QT_RCC_MANGLE_NAMESPACE0(name), QT_RCC_MANGLE_NAMESPACE0(QT_NAMESPACE))
#else
#   define QT_RCC_PREPEND_NAMESPACE(name) name
#   define QT_RCC_MANGLE_NAMESPACE(name) name
#endif

#ifdef QT_NAMESPACE
namespace QT_NAMESPACE {
#endif

bool qRegisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

bool qUnregisterResourceData(int, const unsigned char *, const unsigned char *, const unsigned char *);

#ifdef QT_NAMESPACE
}
#endif

int QT_RCC_MANGLE_NAMESPACE(qInitResources_textFile)();
int QT_RCC_MANGLE_NAMESPACE(qInitResources_textFile)()
{
    QT_RCC_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_textFile)();
int QT_RCC_MANGLE_NAMESPACE(qCleanupResources_textFile)()
{
    QT_RCC_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x2, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

namespace {
   struct initializer {
       initializer() { QT_RCC_MANGLE_NAMESPACE(qInitResources_textFile)(); }
       ~initializer() { QT_RCC_MANGLE_NAMESPACE(qCleanupResources_textFile)(); }
   } dummy;
}
