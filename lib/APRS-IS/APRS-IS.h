
#ifndef APRS_IS_Lib_h_
#define APRS_IS_Lib_h_

#include <APRS-Decoder.h>
#include <APRSExtMessage.h>
#include <WiFi.h>

class APRS_IS {
public:
  void setup(const String &user, const String &passcode, const String &tool_name, const String &version);

  bool connect(const String &server, const int port);
  bool connect(const String &server, const int port, const String &filter);
  bool connected();

  bool sendMessage(const String &message);
  bool sendMessage(const std::shared_ptr<APRSExtMessage> message);

  int available();

  String                          getMessage();
  std::shared_ptr<APRSExtMessage> getAPRSExtMessage();

private:
  String     _user;
  String     _passcode;
  String     _tool_name;
  String     _version;
  WiFiClient _client;

  bool _connect(const String &server, const int port, const String &login_line);
};

#endif
