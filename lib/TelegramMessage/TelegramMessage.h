#ifndef Telegram_H_
#define Telegram_H_

class TelegramBody {
public:
  TelegramBody();
  virtual ~TelegramBody();

  String getData() const;
  void   setData(const String &data);

  virtual String toString() const;

private:
  String _data;
};

class TelegramMessage {
public:
  TelegramMessage();
  explicit TelegramMessage(TelegramMessage &other_msg);
  TelegramMessage &operator=(TelegramMessage &other_msg);
  virtual ~TelegramMessage();

  unsigned long       getTime() const;
  void                setTime(const unsigned long &time);
  TelegramBody *const getBody();

  virtual String toString() const;

private:
  unsigned long       _time = 0;
  TelegramBody *const _body;
};

#endif
