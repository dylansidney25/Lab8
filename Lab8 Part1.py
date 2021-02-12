from guizero import App, Slider
from gpiozero import AngularServo
from time import sleep

def Turn_Horizontal(slider_value):
    n = int(slider_value)
    servo_Horizontal = AngularServo(17, min_angle=-90, max_angle=90, min_pulse_width = minPWM, max_pulse_width = maxPWM)
    servo_Horizontal.angle = n
    sleep(2)
    
def Turn_Vertical(slider_value):
    n = int(slider_value)
    servo_Vertical = AngularServo(27, min_angle=-90, max_angle=90, min_pulse_width = minPWM, max_pulse_width = maxPWM)
    servo_Vertical.angle = n
    sleep(2)
    
correction1 = 0.45
correction2 = -0.35
maxPWM = ((2 + correction1) / 1000)
minPWM = ((1 + correction2) / 1000)
    
app = App(title = "servo control", width = 800, height = 150)
app.bg = "blue"

slider_Horizontal = Slider(app, height = 40, width = 750, start = -90, end = 90, command = Turn_Horizontal)
slider_Horizontal.bg = "red"

slider_Vertical = Slider(app, height = 40, width = 750, start = -90, end = 90, command = Turn_Vertical)
slider_Vertical.bg = "red"
app.display()


    