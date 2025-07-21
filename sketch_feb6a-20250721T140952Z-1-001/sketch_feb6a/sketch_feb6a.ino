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

// // Servo motor
// Servo myServo;
// bool servoActive = false;
// unsigned long servoStartTime = 0;

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
//     Serial.println("Rotating servo motor to 90°...");
//     myServo.write(90);  // Rotate to 90°
//     servoStartTime = millis();
//     servoActive = true;  // Set flag to return after 10 sec
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

//   // Attach servo motor
//   myServo.attach(14);  // Servo connected to GPIO 14
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
//     while (!feedbackReceived && millis() - startTime < 10000) {
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

//   // Return servo to 0° after 10 sec
//   if (servoActive && millis() - servoStartTime >= 10000) {
//     Serial.println("Returning servo to 0°...");
//     myServo.write(0);
//     servoActive = false; // Reset flag
//   }

//   // Clean up WebSocket clients periodically
//   ws.cleanupClients();
// }
























// #include <WiFi.h>
// #include <AsyncTCP.h>
// #include <ESPAsyncWebServer.h>
// #include <ESP32Servo.h>

// // Wi-Fi credentials
// const char* ssid = "hehe";
// const char* password = "password";

// // Ultrasonic sensor 1 (Triggering action)
// const int trigPin1 = 27;
// const int echoPin1 = 26;

// // Ultrasonic sensor 2 (Resetting servo)
// const int trigPin2 = 25;
// const int echoPin2 = 33;

// // Servo motor
// Servo myServo; 
// bool servoActive = false;

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
//     Serial.println("Rotating servo motor to 90°...");
//     myServo.write(90);  // Rotate to 90°
//     servoActive = true;  // Set flag to wait for second sensor
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
//   pinMode(trigPin1, OUTPUT);
//   pinMode(echoPin1, INPUT);
//   pinMode(trigPin2, OUTPUT);
//   pinMode(echoPin2, INPUT);
//   pinMode(ledPin, OUTPUT);

//   // Attach servo motor
//   myServo.attach(14);  // Servo connected to GPIO 14
//   myServo.write(0);    // Set initial servo position
// }

// // Function to get distance from an ultrasonic sensor
// float getDistance(int trigPin, int echoPin) {
//   digitalWrite(trigPin, LOW);
//   delayMicroseconds(2);
//   digitalWrite(trigPin, HIGH);
//   delayMicroseconds(10);
//   digitalWrite(trigPin, LOW);

//   long duration = pulseIn(echoPin, HIGH);
//   return duration * 0.034 / 2;
// }

// void loop() {
//   float distance1 = getDistance(trigPin1, echoPin1);
//   float distance2 = getDistance(trigPin2, echoPin2);

//   // Trigger WebSocket notification if Sensor 1 detects an object within 10 cm
//   if (distance1 > 0 && distance1 < 10 && millis() - lastTriggerTime > debounceDelay) {
//     Serial.println("Object detected within 10 cm (Sensor 1)!");
//     notifyClients("SENSOR_TRIGGERED");
//     lastTriggerTime = millis();
//     feedbackReceived = false;

//     // Wait for feedback
//     unsigned long startTime = millis();
//     while (!feedbackReceived && millis() - startTime < 10000) {
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

//   // Wait for Sensor 2 to detect an object to reset servo
//   if (servoActive && distance2 > 0 && distance2 < 10) {
//     Serial.println("Object detected within 10 cm (Sensor 2)! Returning servo to 0°...");
//     myServo.write(0);
//     servoActive = false; // Reset flag
//   }

//   // Clean up WebSocket clients periodically
//   ws.cleanupClients();
// }









#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <ESP32Servo.h>

// Wi-Fi credentials
const char* ssid = "hehe";
const char* password = "password";

// Ultrasonic sensor 1 (Triggering action)
const int trigPin1 = 27;
const int echoPin1 = 26;

// Ultrasonic sensor 2 (Resetting servo)
const int trigPin2 = 25;
const int echoPin2 = 33;

// Servo motor
Servo myServo; 
bool sensor1Active = true;  // Sensor 1 starts active
bool servoActive = false;   // Servo starts inactive

// LED pin
const int ledPin = 2;

// WebSocket server
AsyncWebServer server(81);
AsyncWebSocket ws("/ws");

// Variables
unsigned long lastTriggerTime = 0;
const unsigned long debounceDelay = 3000;
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
    Serial.println("Rotating servo motor to 90°...");
    myServo.write(90);
    servoActive = true;  // Set flag for Sensor 2 activation
  } else {
    Serial.println("Turning on LED...");
    digitalWrite(ledPin, HIGH);
    delay(2000);
    digitalWrite(ledPin, LOW);
  }

  feedbackReceived = true;
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
  pinMode(trigPin1, OUTPUT);
  pinMode(echoPin1, INPUT);
  pinMode(trigPin2, OUTPUT);
  pinMode(echoPin2, INPUT);
  pinMode(ledPin, OUTPUT);

  // Attach servo motor
  myServo.attach(14);
  myServo.write(0);
}

// Function to get distance from an ultrasonic sensor
float getDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  return duration * 0.034 / 2;
}

void loop() {
  if (sensor1Active) {
    float distance1 = getDistance(trigPin1, echoPin1);

    // Trigger WebSocket notification if Sensor 1 detects an object within 10 cm
    if (distance1 > 0 && distance1 < 10 && millis() - lastTriggerTime > debounceDelay) {
      Serial.println("Object detected within 10 cm (Sensor 1)!");

      notifyClients("SENSOR_TRIGGERED");
      lastTriggerTime = millis();
      feedbackReceived = false;
      sensor1Active = false;  // Disable Sensor 1 until Sensor 2 detects

      // Wait for feedback
      unsigned long startTime = millis();
      while (!feedbackReceived && millis() - startTime < 10000) {
        delay(1000);
        ws.cleanupClients();
      }

      if (!feedbackReceived) {
        Serial.println("No feedback received. Default action triggered.");
        digitalWrite(ledPin, HIGH);
        delay(2000);
        digitalWrite(ledPin, LOW);
      }
    }
  }

  if (servoActive) {
    float distance2 = getDistance(trigPin2, echoPin2);

    // Reset servo and enable Sensor 1 when Sensor 2 detects an object
    if (distance2 > 0 && distance2 < 10) {
      Serial.println("Object detected within 10 cm (Sensor 2)! Resetting servo and reactivating Sensor 1...");
      myServo.write(0);
      servoActive = false;
      sensor1Active = true;  // Re-enable Sensor 1
    }
  }

  ws.cleanupClients();
}

