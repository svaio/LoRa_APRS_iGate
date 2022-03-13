#ifndef TASK_MQTT_H_
#define TASK_MQTT_H_

#include <APRSExtMessage.h>
#include <PubSubClient.h>
#include <TaskManager.h>
#include <WiFi.h>

class MQTTTask : public Task {
public:
  MQTTTask(TaskQueue<std::shared_ptr<APRSExtMessage>> &toMQTT);
  virtual ~MQTTTask();

  virtual bool setup(System &system) override;
  virtual bool loop(System &system) override;

private:
  TaskQueue<std::shared_ptr<APRSExtMessage>> &_toMQTT;

  WiFiClient   _client;
  PubSubClient _MQTT;

  bool connect(const System &system);
};

#endif
