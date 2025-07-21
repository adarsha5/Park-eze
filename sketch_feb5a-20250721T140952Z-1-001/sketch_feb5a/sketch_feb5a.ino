// #include <WiFi.h>
// #include <AsyncTCP.h>
// #include <ESPAsyncWebServer.h>

// // Replace these with your network credentials
// const char* ssid = "hehe";
// const char* password = "password";
// int a = 10;

// // Create AsyncWebServer on port 81
// AsyncWebServer server(81);
// AsyncWebSocket ws("/ws");  // WebSocket endpoint

// // Define the sensor pin
// const int sensorPin = 5;  // GPIO pin connected to the sensor
// int lastSensorState = LOW;

// // Function to send messages to all connected WebSocket clients
// void notifyClients(const char* message) {
//   ws.textAll(message);
// }

// // WebSocket event handler
// void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
//   AwsFrameInfo info = (AwsFrameInfo)arg;
//   if (info->opcode == WS_TEXT) {
//     String message = String((char*)data).substring(0, len);
//     Serial.println("Received from client: " + message);

//     // Process feedback message
//     if (message.startsWith("Feedback:")) {
//       Serial.println("Feedback received: " + message);
//     }
//   }
// }

// // WebSocket event callback
// void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
//   if (type == WS_EVT_CONNECT) {
//     Serial.println("WebSocket client connected");
//   } else if (type == WS_EVT_DISCONNECT) {
//     Serial.println("WebSocket client disconnected");
//   } else if (type == WS_EVT_DATA) {
//     handleWebSocketMessage(arg, data, len);
//   }
// }

// void setup() {
//   // Initialize Serial Monitor
//   Serial.begin(115200);

//   // Connect to Wi-Fi
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.println("Connecting to Wi-Fi...");
//   }
//   Serial.println("Connected to Wi-Fi");
//   Serial.print("IP Address: ");
//   Serial.println(WiFi.localIP());

//   // Initialize sensor pin
//   pinMode(sensorPin, INPUT);

//   // Attach WebSocket event handler
//   ws.onEvent(onEvent);
//   server.addHandler(&ws);

//   // Start the WebSocket server
//   server.begin();
//   Serial.println("WebSocket server started");
// }

// void loop() {
//   // Check sensor state
//   int sensorState = digitalRead(sensorPin);

//   // Simulate a sensor trigger
//   while (a > 0) {
//     Serial.println("Sensor triggered!");
//     notifyClients("SENSOR_TRIGGERED");
//     a--;
//     delay(1000);  // Add a small delay to avoid flooding the network
//   }

//   // Update the last sensor state
//   lastSensorState = sensorState;

//   // Handle WebSocket events
//   ws.cleanupClients();
// }






// #include <WiFi.h>
// #include <AsyncTCP.h>
// #include <ESPAsyncWebServer.h>
// #include <Servo.h>

// // Replace these with your network credentials
// const char* ssid = "hehe";
// const char* password = "password";

// // Ultrasonic sensor pins
// const int trigPin = 12; // Trigger pin
// const int echoPin = 13; // Echo pin

// // Servo motor
// Servo myServo;

// // LED pin
// const int ledPin = 2;

// // Create AsyncWebServer on port 81
// AsyncWebServer server(81);
// AsyncWebSocket ws("/ws");  // WebSocket endpoint

// // Function to send messages to all connected WebSocket clients
// void notifyClients(const char* message) {
//   ws.textAll(message);
// }

// // WebSocket event handler
// void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
//   AwsFrameInfo info = (AwsFrameInfo)arg;
//   if (info->opcode == WS_TEXT) {
//     String message = String((char*)data).substring(0, len);
//     Serial.println("Received from client: " + message);

//     if (message == "YES") {
//       Serial.println("Rotating servo motor...");
//       myServo.write(90);  // Rotate servo to 90 degrees
//       delay(2000);
//       myServo.write(0);   // Reset servo to 0 degrees
//     } else {
//       Serial.println("Turning on LED...");
//       digitalWrite(ledPin, HIGH);
//       delay(2000);
//       digitalWrite(ledPin, LOW);
//     }
//   }
// }

// // WebSocket event callback
// void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
//   if (type == WS_EVT_CONNECT) {
//     Serial.println("WebSocket client connected");
//   } else if (type == WS_EVT_DISCONNECT) {
//     Serial.println("WebSocket client disconnected");
//   } else if (type == WS_EVT_DATA) {
//     handleWebSocketMessage(arg, data, len);
//   }
// }

// void setup() {
//   // Initialize Serial Monitor
//   Serial.begin(115200);

//   // Connect to Wi-Fi
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.println("Connecting to Wi-Fi...");
//   }
//   Serial.println("Connected to Wi-Fi");
//   Serial.print("IP Address: ");
//   Serial.println(WiFi.localIP());

//   // Attach WebSocket event handler
//   ws.onEvent(onEvent);
//   server.addHandler(&ws);
//   server.begin();
//   Serial.println("WebSocket server started");

//   // Initialize ultrasonic sensor pins
//   pinMode(trigPin, OUTPUT);
//   pinMode(echoPin, INPUT);

//   // Initialize LED pin
//   pinMode(ledPin, OUTPUT);

//   // Attach servo motor
//   myServo.attach(14); // Attach servo to GPIO 14
//   myServo.write(0);   // Set initial servo position
// }

// float getDistance() {
//   // Send a 10-microsecond pulse to the trigger pin
//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);

//   // Measure the echo pulse duration
//   long duration = pulseIn(echoPin, HIGH);

//   // Calculate distance in centimeters
//   float distance = duration * 0.034 / 2;
//   return distance;
// }

// void loop() {
//   float distance = getDistance();
//   if (distance > 0 && distance < 10) {
//     Serial.println("Object detected within 10 cm!");
//     notifyClients("SENSOR_TRIGGERED");

//     // Wait for feedback from the client
//     delay(5000);  // Wait for 5 seconds to receive feedback
//   }

//   // Handle WebSocket events
//   ws.cleanupClients();
// }

















// #include <WiFi.h>
// #include <AsyncTCP.h>
// #include <ESPAsyncWebServer.h>
// #include <Servo.h>

// // Wi-Fi credentials
// const char* ssid = "hehe";
// const char* password = "password";

// // Ultrasonic sensor pins
// const int trigPin = 12; // Trigger pin
// const int echoPin = 13; // Echo pin

// // Servo motor
// Servo myServo;

// // LED pin
// const int ledPin = 2;

// // WebSocket server
// AsyncWebServer server(81);
// AsyncWebSocket ws("/ws");  // WebSocket endpoint

// // Variables
// unsigned long lastTriggerTime = 0;
// const unsigned long debounceDelay = 3000;  // Debounce time (3 seconds)
// bool feedbackReceived = false;

// // Function to send WebSocket messages
// void notifyClients(const char* message) {
//   ws.textAll(message);
// }

// // Handle WebSocket messages
// void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
//   String message = String((char*)data).substring(0, len);
//   Serial.println("Received from client: " + message);

//   if (message == "YES") {
//     Serial.println("Rotating servo motor...");
//     myServo.write(90);  // Rotate to 90°
//     delay(2000);
//     myServo.write(0);   // Return to 0°
//   } else {
//     Serial.println("Turning on LED...");
//     digitalWrite(ledPin, HIGH);
//     delay(2000);
//     digitalWrite(ledPin, LOW);
//   }

//   feedbackReceived = true;  // Mark feedback as received
// }

// // WebSocket event callback
// void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
//   if (type == WS_EVT_DATA) {
//     handleWebSocketMessage(arg, data, len);
//   }
// }

// void setup() {
//   Serial.begin(115200);

//   // Connect to Wi-Fi
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.println("Connecting to Wi-Fi...");
//   }
//   Serial.println("Connected to Wi-Fi");
//   Serial.print("IP Address: ");
//   Serial.println(WiFi.localIP());

//   // Initialize WebSocket server
//   ws.onEvent(onEvent);
//   server.addHandler(&ws);
//   server.begin();

//   // Initialize sensor and peripherals
//   pinMode(trigPin, OUTPUT);
//   pinMode(echoPin, INPUT);
//   pinMode(ledPin, OUTPUT);
//   myServo.attach(14);  // Servo connected to GPIO 14
//   myServo.write(0);
// }

// // Function to get distance from the ultrasonic sensor
// float getDistance() {
//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);

//   long duration = pulseIn(echoPin, HIGH);
//   return duration * 0.034 / 2;
// }

// void loop() {
//   float distance = getDistance();

//   // Trigger WebSocket notification if distance < 10 cm
//   if (distance > 0 && distance < 10 && millis() - lastTriggerTime > debounceDelay) {
//     Serial.println("Object detected within 10 cm!");
//     notifyClients("SENSOR_TRIGGERED");
//     lastTriggerTime = millis();
//     feedbackReceived = false;

//     // Wait for feedback
//     unsigned long startTime = millis();
//     while (!feedbackReceived && millis() - startTime < 5000) {
//       ws.cleanupClients();  // Keep WebSocket clients active
//     }

//     if (!feedbackReceived) {
//       Serial.println("No feedback received. Default action triggered.");
//       digitalWrite(ledPin, HIGH);
//       delay(2000);
//       digitalWrite(ledPin, LOW);
//     }
//   }

//   // Clean up WebSocket clients
//   ws.cleanupClients();
// }








#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESP32Servo.h>

// Wi-Fi credentials
const char* ssid = "hehe";
const char* password = "password";

// Ultrasonic sensor pins
const int trigPin = 27; // Trigger pin
const int echoPin = 26; // Echo pin

// Servo motor
Servo myServo;

// LED pin
const int ledPin = 2;

// WebSocket server
AsyncWebServer server(81);
AsyncWebSocket ws("/ws");  // WebSocket endpoint

// Variables
unsigned long lastTriggerTime = 0;
const unsigned long debounceDelay = 3000;  // Debounce time (3 seconds)
bool feedbackReceived = false;

// Function to send WebSocket messages
void notifyClients(const char* message) {
  ws.textAll(message);
}

// Handle WebSocket messages
void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
  String message = String((char*)data).substring(0, len);
  Serial.println("Received from client: " + message);

  if (message == "YES") {
    Serial.println("Rotating servo motor... I am working");
    myServo.write(90);  // Rotate to 90°
    
    delay(2000);
    myServo.write(0);   // Return to 0°
  } else {
    Serial.println("Turning on LED...");
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(ledPin, LOW);
  }

  feedbackReceived = true;  // Mark feedback as received
}

// WebSocket event callback
void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
  if (type == WS_EVT_DATA) {
    handleWebSocketMessage(arg, data, len);
  }
}

void setup() {
  Serial.begin(115200);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to Wi-Fi...");
  }
  Serial.println("Connected to Wi-Fi");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Initialize WebSocket server
  ws.onEvent(onEvent);
  server.addHandler(&ws);
  server.begin();

  // Initialize sensor and peripherals
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(ledPin, OUTPUT);

  // Attach servo motor using ESP32Servo
  myServo.attach(14);  // Servo connected to GPIO 14
  myServo.write(0);    // Set initial servo position
}

// Function to get distance from the ultrasonic sensor
float getDistance() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void loop() {
  float distance = getDistance();

  // Trigger WebSocket notification if distance < 10 cm
  if (distance > 0 && distance < 10 && millis() - lastTriggerTime > debounceDelay) {
    Serial.println("Object detected within 10 cm!");
    notifyClients("SENSOR_TRIGGERED");
    lastTriggerTime = millis();
    feedbackReceived = false;

    // Wait for feedback
    unsigned long startTime = millis();
    int a =10;
    while (!feedbackReceived && millis() - startTime < 10000) {
      Serial.println("I am waiting for second = ");
      Serial.println(a);
      a = a-1;
      delay(1000);
      ws.cleanupClients();  // Keep WebSocket clients active
    }

    if (!feedbackReceived) {
      Serial.println("No feedback received. Default action triggered.");
      digitalWrite(ledPin, HIGH);
      delay(2000);
      digitalWrite(ledPin, LOW);
    }
  }

  // Clean up WebSocket clients
  ws.cleanupClients();
}









// #include <WiFi.h>
// #include <AsyncTCP.h>
// #include <ESPAsyncWebServer.h>
// #include <ESP32Servo.h>

// // Wi-Fi credentials
// const char* ssid = "hehe";
// const char* password = "password";

// // Ultrasonic sensor pins
// const int trigPin = 27; // Trigger pin
// const int echoPin = 26; // Echo pin
// // Sensor 2 (new HC-SR04) pins
// const int trigPin2 = 33; // Trigger pin for sensor2 (adjust as needed)
// const int echoPin2 = 32; // Echo pin for sensor2 (adjust as needed)
// // Servo motor
// Servo myServo;

// // LED pin
// const int ledPin = 2;

// // WebSocket server
// AsyncWebServer server(81);
// AsyncWebSocket ws("/ws");  // WebSocket endpoint

// // Variables
// unsigned long lastTriggerTime = 0;
// const unsigned long debounceDelay = 3000;  // Debounce time (3 seconds)
// bool feedbackReceived = false;

// // Function to send WebSocket messages
// void notifyClients(const char* message) {
//   ws.textAll(message);
// }

// // Handle WebSocket messages
// void handleWebSocketMessage(void *arg, uint8_t *data, size_t len) {
//   String message = String((char*)data).substring(0, len);
//   Serial.println("Received from client: " + message);

//   if (message == "YES") {
//     Serial.println("Rotating servo motor... I am working");
//     myServo.write(90);  // Rotate to 90°
//     // delay(2000);
//     while(1){
//       digitalWrite(trigPin2, LOW);
//       delayMicroseconds(2);
//       digitalWrite(trigPin2, HIGH);
//       delayMicroseconds(10);
//       digitalWrite(trigPin2, LOW);

//       long duration = pulseIn(echoPin, HIGH);
//       int distance = duration * 0.034 / 2;
//       if (distance > 0 && distance < 10 && millis() - lastTriggerTime > debounceDelay) {
//         break;
//       }
//     }
//     myServo.write(0);   // Return to 0°
//   } else {
//     Serial.println("Turning on LED...");
//     digitalWrite(ledPin, HIGH);
//     delay(2000);
//     digitalWrite(ledPin, LOW);
//   }

//   feedbackReceived = true;  // Mark feedback as received
// }

// // WebSocket event callback
// void onEvent(AsyncWebSocket *server, AsyncWebSocketClient *client, AwsEventType type, void *arg, uint8_t *data, size_t len) {
//   if (type == WS_EVT_DATA) {
//     handleWebSocketMessage(arg, data, len);
//   }
// }

// void setup() {
//   Serial.begin(115200);

//   // Connect to Wi-Fi
//   WiFi.begin(ssid, password);
//   while (WiFi.status() != WL_CONNECTED) {
//     delay(1000);
//     Serial.println("Connecting to Wi-Fi...");
//   }
//   Serial.println("Connected to Wi-Fi");
//   Serial.print("IP Address: ");
//   Serial.println(WiFi.localIP());

//   // Initialize WebSocket server
//   ws.onEvent(onEvent);
//   server.addHandler(&ws);
//   server.begin();

//   // Initialize sensor and peripherals
//   pinMode(trigPin, OUTPUT);
//   pinMode(echoPin, INPUT);
//   pinMode(ledPin, OUTPUT);

//   // Attach servo motor using ESP32Servo
//   myServo.attach(5);  // Servo connected to GPIO 14
//   myServo.write(0);    // Set initial servo position
// }

// // Function to get distance from the ultrasonic sensor
// float getDistance() {
//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);

//   long duration = pulseIn(echoPin, HIGH);
//   return duration * 0.034 / 2;
// }

// void loop() {
//   float distance = getDistance();

//   // Trigger WebSocket notification if distance < 10 cm
//   if (distance > 0 && distance < 10 && millis() - lastTriggerTime > debounceDelay) {
//     Serial.println("Object detected within 10 cm!");
//     notifyClients("SENSOR_TRIGGERED");
//     lastTriggerTime = millis();
//     feedbackReceived = false;

//     // Wait for feedback
//     unsigned long startTime = millis();
//     int a =10;
//     while (!feedbackReceived && millis() - startTime < 10000) {
//       Serial.println("I am waiting for second = ");
//       Serial.println(a);
//       a = a-1;
//       delay(1000);
//       ws.cleanupClients();  // Keep WebSocket clients active
//     }

//     if (!feedbackReceived) {
//       Serial.println("No feedback received. Default action triggered.");
//       digitalWrite(ledPin, HIGH);
//       delay(2000);
//       digitalWrite(ledPin, LOW);
//     }
//   }

//   // Clean up WebSocket clients
//   ws.cleanupClients();
// }

