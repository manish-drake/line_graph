#ifndef GRAPHSPLUGIN_H
#define GRAPHSPLUGIN_H

#include <QQmlExtensionPlugin>

class GraphsPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)
public:
    void registerTypes(const char *uri);
};

#endif // GRAPHSPLUGIN_H
