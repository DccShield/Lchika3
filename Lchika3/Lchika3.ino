//
// D2 port に接続したLEDを1秒周期で点滅を繰り替えす
//

unsigned long PreviosTime = 0;  // PreviosTime 前時間

void setup() {
  pinMode(2, OUTPUT);           // D2 portは出力ポート
  digitalWrite(2, LOW);         // 初期はLOW(OFF)出力
  PreviosTime = millis();       // setup()終了時の時刻をPreviosTimeに格納
}

void loop() {


  if( (millis() - PreviosTime ) >= 1000 ){  // 1000:1000msec 前回から1000ms経過したかチェック
    PreviosTime = millis();                 // 現在の時刻に更新
    led_chika();                            // led点滅処理
  }
}

//
// led点滅処理
//
void led_chika(){
  static char ledState = 0;                 // ledの点灯状態格納用（staticは,ずっと忘れない変数）

  switch(ledState){
      case 0:                               // ledState = 0 つまり消灯だったら、LED点灯して、lesState=1
              digitalWrite(2, HIGH);
              ledState = 1;
              break;
      case 1:                               // ledState = 1 点灯だったら、LED消灯して、lesState=0
              digitalWrite(2, LOW);
              ledState = 0;
              break;
      default:                              // 万が一それ以外の数値がはいっていたら何もしない
              break;      
    }
}
