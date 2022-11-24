# Thermostat using ThingsBoard-IoT-Platform
The IoT is an implimenting intelligence in the physical object and connect them to cloud to Visualize the physical device data on the cloud we need to develop the web application.
But now a days we have luxury of ready to use IoT cloud platforms available to build the IoT applications.
So instead of creating the web application for any IoT use case we simply choose the available IoT platform and build an application.

The ThingsBoard is a most popular IoT Platform and provides plenty of Features.

ThingsBoard Provide main three types of Installations,
1. Community Edition [Free to use]
2. Professional Edition
3. Cloud Edition 

## ThingsBoard Installation

Thingsboard provides variety of installation processes.
For the ThingsBoard CE Installation you can check out the below link,
https://thingsboard.io/docs/user-guide/install/installation-options/ 

## Getting Started with ThingsBoard

In this tutorial, we will see the most popular ThingsBoard CE IoT Platform and Its Features.
To create the device and respective dashboard for the device please check the official site via link below,
https://thingsboard.io/docs/getting-started-guides/helloworld/

To connect the device you need to get the device credentials first. ThingsBoard supports various device credentials.
We recommend using default auto-generated credentials which is access token for this guide.

In the device details section we get the access credentials like Access Token.

Now you are ready to publish telemetry data on behalf of your device. 
We will use simple commands to publish data over HTTP or MQTT in this example.
To publish the data first we use the CURL API. [Install the CURL based on OS used on the system]

**CURL API Command** -

```sh
$ curl -v -X POST -d "{\"temperature\": 25}" $THINGSBOARD_HOST_NAME/api/v1/$ACCESS_TOKEN/telemetry --header "Content-Type:application/json"
```

Where, 
	**THINGSBOARD_HOST_NAME** - refere to your ThingsBoard Installation
	**ACCESS_TOKEN** - Device Accescibility Token
  
We consider the ThingsBoard is installed on the local System.	

```sh
$ curl -v -X POST -d "{\"temperature\": 25}" http://localhost:8080/api/v1/ABC123/telemetry --header "Content-Type:application/json"
```

**Device details** - 
![Device Access Token](https://user-images.githubusercontent.com/84657983/203525521-b2c42343-aab0-43b7-8360-cea69424c506.png)


**CLI output for CURL API Call** -
![CLI Output](https://user-images.githubusercontent.com/84657983/203525781-b539ebbf-913f-409a-af0e-f49f3fc51052.png)


**Latest Telemetry** -
![telemetry section](https://user-images.githubusercontent.com/84657983/203525665-329d295a-d2fa-430b-bef9-2008b951a18e.png)


## Thermostat Application Development.
## ESP32 Connectivity with ThingsBoard

Now we will setup the actual device and publish the data to Thingsboard.
We use ESP32 Development Board and DHT11 Sensor to publish the data [temperature and Humidity] to thingsBoard.
To program the ESP32 we use Arduino IDE.
We need to Install the ESP32 packege in Arduino IDE.

**Process**:
Open the Arduino IDE -----> Preferences-----> Enter "https://dl.espressif.com/dl/package_esp32_index.json" into the "Additional Board Manager URLs" field. Then, click the "OK" button.------> Open the Boards Manager. Go to Tools > Board > Boards Manager --------> Search for ESP32 and press install button for the "ESP32 by Espressif Systems".

Select your Board in Tools > Board menu (in my case it’s the DOIT ESP32 DEVKIT V1) to run the programs on ESP32 board.
 

**Required Libraries **-
1. DHT Sensor library - Link - https://github.com/adafruit/DHT-sensor-library
2. PubSubClient Library - Link - https://github.com/asksensors/pubsubclient
3. ArduinoJson Library - Link - https://github.com/bblanchon/ArduinoJson

**Thermostat Dashboard** -
![dashboard github](https://user-images.githubusercontent.com/84657983/203525113-9cb8e3d1-600b-43fb-b8e7-065d49eb84f0.png)

###### Thank you Very Much..!
