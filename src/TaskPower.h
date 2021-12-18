#ifndef TASK_POWER_H_
#define TASK_POWER_H_

#include <APRSExtMessage.h>
#include <TaskManager.h>
#include <power_management_adc.h>

class PowerTask : public Task {
public:
  PowerTask(TaskQueue<std::shared_ptr<APRSExtMessage>> &_fromPower);
  virtual ~PowerTask();

  virtual bool setup(System &system) override;
  virtual bool loop(System &system) override;

private:
  PowerManagementADC _powerManagementADC;
  int                _powerReadDelay    = 30000;
  unsigned long      _lastTimePowerRead = 0;
  double             _lastVoltage       = 0.0;

  TaskQueue<std::shared_ptr<APRSExtMessage>> &_fromPower;
};
#endif
