#include "graphsplugin.h"
#include "linegraph.h"


void GraphsPlugin::registerTypes(const char *uri)
{
    qmlRegisterType<LineGraph>(uri, 1, 0, "LineGraph");
}
