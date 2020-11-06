import Adafruit_BBIO.PWM as PWM
import Adafruit_BBIO.GPIO as GPIO

GPIO.setup("P8_12", GPIO.IN)
old_switch_state = 0
servo_pin = "P8_19"
duty_min = 3
duty_max = 14.5
duty_span = duty_max - duty_min
flag = 0
PWM.start(servo_pin, (100-duty_min), 60.0,1)
 
while True:
    new_switch_state = GPIO.input("P8_12")
    if new_switch_state == 1 and old_switch_state == 0 :
        flag = flag + 1 
        print(flag)
    angle = flag * 45
    
    angle_f = float(angle)
    duty = 100 - ((angle_f / 180) * duty_span + duty_min) 
    PWM.set_duty_cycle(servo_pin, duty)