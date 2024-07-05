#include <Arduino.h>

const char *htmlPage = R"rawliteral(
<!DOCTYPE HTML>
<html>
<head>
  <title>Slider and Button Control</title>
  <meta name="viewport" content="width=device-width, initial-scale=1">
  <style>
    body { 
        text-align: center;
        font-family: Arial, Helvetica, sans-serif;
        display: flex;
        justify-content: center;
        flex-direction: column;
        gap: 1rem;
    }
    #hue-gradient {
        height: 1rem;
        width: 100%;
        background: linear-gradient(
            to right,
            #ff0000 0%,
            #ffff00 17%,
            #00ff00 33%,
            #00ffff 50%,
            #0000ff 67%,
            #ff00ff 83%,
            #ff0000 100%
        );
    }
  </style>
</head>
<body>
  <h2>Control Panel</h2>
  <label for="slider1">Hue:</label>
  <div id="hue-gradient"></div>
  <input type="range" id="slider1" class="slider" min="0" max="255" value="50"><br><br>
  <label for="slider2">Saturation:</label>
  <input type="range" id="slider2" class="slider" min="0" max="255" value="50"><br><br>
  <label for="slider3">Luma:</label>
  <input type="range" id="slider3" class="slider" min="0" max="255" value="50"><br><br>
  <button onclick="sendData()">Submit</button>
  <script>
    function sendData() {
      var slider1Value = document.getElementById('slider1').value;
      var slider2Value = document.getElementById('slider2').value;
      var slider3Value = document.getElementById('slider3').value;
      var xhr = new XMLHttpRequest();
      xhr.open('GET', '/update?slider1=' + slider1Value + '&slider2=' + slider2Value + '&slider3=' + slider3Value, true);
      xhr.send();
    }
  </script>
</body>
</html>
)rawliteral";