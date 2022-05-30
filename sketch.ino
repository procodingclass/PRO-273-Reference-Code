#include <SD.h>
#include <ezButton.h>

File file;

int book_num = 0;
int book_state = 0;
int prev_book_num = -1;

ezButton next(2);
ezButton prev(3);
ezButton select_book(4);
ezButton open_book(5);

void setup() {
  Serial.begin(9600);
  SD.begin();

  next.setDebounceTime(50);
  prev.setDebounceTime(50);
  select_book.setDebounceTime(50);
  open_book.setDebounceTime(50);

  /*file = SD.open("harry.txt", FILE_READ);
    Serial.print("Total characters :");
    Serial.println(file.size());

    if (file) {
    Serial.println("HARRY POTTER : ");
    delay(2000);
    while (file.available()) {
      char data = file.read();
      Serial.print(data);
    }
    Serial.println();
    file.close();
    }
    Serial.println("File read successfully");*/
}


void loop() {

  next.loop();
  prev.loop();
  select_book.loop();
  open_book.loop();

  if (next.isPressed()) {
    book_num++;
  }
  else if (prev.isPressed()) {
    book_num--;
  }
  else if (select_book.isPressed()) {
    book_state=0;
    prev_book_num=-1;
  }
  else if (open_book.isPressed()) {
    book_state=1;
  }

  book_num = constrain(book_num, 0, 1);
  check_book();

  //  for better working of simulator
  delay(10);
}

void check_book() {
  if (prev_book_num != book_num) {
    prev_book_num = book_num;
    if (book_num) {
      Serial.println("Think and Grow Rich");
    }
    else {
      Serial.println("Harry Potter");
    }
  }
}