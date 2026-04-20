# mqttTrain

Arduino UNO R4 WiFi を使った MQTT 送信の練習プロジェクトです。

## 概要

5秒ごとにダミーの温度データを MQTT ブローカーへ送信します。

- **ボード**: Arduino UNO R4 WiFi
- **フレームワーク**: Arduino (PlatformIO)
- **ライブラリ**: ArduinoMqttClient

## トピック

| トピック | 内容 |
|---|---|
| `home/room/tempereture` | 温度データ（℃） |

## セットアップ

### 1. secret.h の作成

`src/secret.h` を作成し、以下を記述してください（このファイルはgitに含まれません）：

```cpp
#define SECRET_SSID     "your_wifi_ssid"
#define SECRET_PASSWORD "your_wifi_password"
#define SECRET_BROKER   "broker_ip_address"
```

### 2. MQTT ブローカーの起動

[Mosquitto](https://mosquitto.org/download/) をインストールし、以下のコマンドで起動します：

```bash
mosquitto -c mosquitto.conf -v
```

### 3. ビルド & 書き込み

PlatformIO を使ってビルド・書き込みを行います。

```bash
pio run --target upload
```
