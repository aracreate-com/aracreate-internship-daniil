unsigned long previousMillis = 0;
const long interval = 10000;
unsigned long startTime;

const int redPin = 5;
const int greenPin = 6;
const int bluePin = 7;

bool flag = false;
int myStatus = 0;
int termStatus = 0;

int color[3];

int red;
int green;
int blue;

void getColorFromTerminal() {
  if (termStatus == 0) {
    Serial.println("Enter a rgb color: ");
    termStatus = 1;
  }

   if (termStatus == 1) {
  
    if (Serial.available()) {
      String input = Serial.readStringUntil('\n');
      
      if (input == 0) {
        return;
      }
      
      if (input.startsWith("rgb")) {
        int firstComma = input.indexOf(',');
        int secondComma = input.lastIndexOf(',');
        int red = input.substring(4, firstComma).toInt();
        int green = input.substring(firstComma + 1, secondComma).toInt();
        int blue = input.substring(secondComma + 1).toInt();
  
//        Serial.println("Your color is:");
//        Serial.println(String(red) + ", "+ String(green) + ", " + String(blue));

        int color[3] = {red, green, blue};
        color[0] = red;
        color[1] = green;
        color[2] = blue;

        termStatus = -1;
        
        return;
        
      } else {
        Serial.println("That's not a rgb color! Enter a rgb color (for example, rgb(255, 255, 255)):");
        termStatus = 0;
      }
    }
  }
}

void setColor(int redValue, int greenValue, int blueValue) {
  analogWrite(redPin, redValue);
  analogWrite(greenPin, greenValue);
  analogWrite(bluePin, blueValue);
}

void setup () {
  Serial.begin(9600);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);
}
void loop () {
  if (myStatus == 0) {
    Serial.println("Do you want to enter the color? (yes/no)");
    unsigned long startTime = millis();
    myStatus = 1;
  }

  if (millis() - startTime < interval && myStatus == 1) {
    if (Serial.available()) {
            
      String answer = Serial.readStringUntil('\n');
      answer.trim();

      if (answer.equalsIgnoreCase("yes")) {
        
        Serial.println("Excellent!");
        flag = true;
        myStatus = 2;
        
      } else if (answer.equalsIgnoreCase("no")) {
        
        Serial.println("OK!");
        myStatus = 2;
        
      } else {
        
        Serial.println("I don't know this answer...");
        myStatus = 0;
        
      }
    }
  }
  if (myStatus == 2) {
    if (!flag) {
      
      red = random(256);
      green = random(256);
      blue = random(256);

      Serial.println("I set lights randomly.");
      myStatus = -1;
      
    } else {
        
        getColorFromTerminal();
  
        red = color[0];
        green = color[1];
        blue = color[2];
        
      }
  }
  
  setColor(red, green, blue);
    
}
