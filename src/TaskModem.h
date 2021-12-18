#ifndef TASK_LORA_H_
#define TASK_LORA_H_

#include <BoardFinder.h>
#include <LoRa_APRS.h>
#include <TaskManager.h>

class ModemTask : public Task {
public:
  explicit ModemTask(TaskQueue<std::shared_ptr<APRSExtMessage>> &fromModem, TaskQueue<std::shared_ptr<APRSExtMessage>> &_toModem);
  virtual ~ModemTask();

  virtual bool setup(System &system) override;
  virtual bool loop(System &system) override;

private:
  LoRa_APRS _lora_aprs;

  TaskQueue<std::shared_ptr<APRSExtMessage>> &_fromModem;
  TaskQueue<std::shared_ptr<APRSExtMessage>> &_toModem;
};

#endif
