import Adafruit_BBIO.ADC as ADC
import Adafruit_BBIO.PWM as PWM
import time
 

sensor_pin = 'P9_40'
servo_pin = "P8_13"
duty_min = 3
duty_max = 14.5
duty_span = duty_max - duty_min

PWM.start(servo_pin, (100-duty_min), 60.0)
angle_f = float(90)
duty = 100 - ((angle_f / 180) * duty_span + duty_min) 
duty_zero = 100 - (0 * duty_span + duty_min) 
ADC.setup()
 
print('Reading\t\tVolts')
 
while True:
    reading = ADC.read(sensor_pin)
    volts = reading
    print('%f\t%f' % (reading, volts))
    if volts >=0.85:
        PWM.set_duty_cycle(servo_pin, duty)
    else:
        PWM.set_duty_cycle(servo_pin, duty_zero)
    
    time.sleep(1)