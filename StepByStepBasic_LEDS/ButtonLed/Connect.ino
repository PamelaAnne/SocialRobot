// check your connection with WiFi and MQTT broker
void connect() {
  Serial.print("checking wifi..."); // you see serial monitor
  while ( status != WL_CONNECTED) { // check if connected
    status = WiFi.begin(WIFI_SSID, WIFI_PASS);
    Serial.print("."); // you see serial monitor
    delay(1000);
  }
  Serial.println("\nconnected to WiFi!\n"); // you see serial monitor

  client.begin(mqttServer, mqttServerPort, net); // check the server

  Serial.println("connecting to broker..."); // you see serial monitor
  while (!client.connect(device, key, secret)) { // check the broker of shiftr.io
    Serial.print("."); // you see serial monitor
    delay(1000);
  }

  Serial.println("Connected to MQTT"); // you see serial monitor

  client.onMessage(messageReceived); // connected with void(messageReceived)

  client.subscribe("/button1");  // What Person1 button sends - can be received in void(messageReceived)
  client.subscribe("/button2");  // What Person2 button sends - can be received in void(messageReceived)
  client.subscribe("/button3");  // What Person3 button sends - can be received in void(messageReceived)
  client.subscribe("/button4");  // What Person4 button sends - can be received in void(messageReceived)
  //++ if someone else want to get in our system
}
