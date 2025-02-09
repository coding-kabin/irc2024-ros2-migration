#!/usr/bin/env python3

'''
Main module for GUI.
'''

import rospy
from std_msgs.msg import Int8, String
from sensor_msgs.msg import Image as RosImage
from PIL import Image, ImageTk
import tkinter as tk
from tkinter import (
    ttk, filedialog, messagebox)
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import (
     FigureCanvasTkAgg)
from matplotlib import style
import cv2
from cv_bridge import CvBridge
import threading
import subprocess
from datetime import datetime
import csv
import os
from  irc2024.msg import *

# global coordinate varibles
atmos_x = []
temp_y = []
humidity_y = []
pressure_y = []

sensor_x = []
co2_y = []
ch4_y = []
co_y = []
user=os.getlogin()


# spectro_time = datetime.now()

spectro_pointer = 0
spectro_x = [410, 435, 460, 485, 510, 535, 560, 585, 610, 645, 680, 705, 730, 760, 810, 860, 900, 940]
spectro_y = [0 for i in range(18)]
terminator_process_1 = None
terminator_process_2 = None
terminator_process_3 = None

# backend functions
# callback functions
def atmos_callback(data):
    global temp_y, humidity_y, pressure_y
    temp_y.append(data.temp)
    humidity_y.append(data.humidity)
    pressure_y.append(data.pressure)
    atmos_plot()
    
def sensor_callback(data):
    global co2_y, ch4_y, co_y
    co2_y.append(data.co2)
    ch4_y.append(data.ch4)
    co_y.append(data.co)
    sensor_plot()

def spectro_callback(data):
    global spectro_pointer
    global spectro_y
    if data.brad !=-1:
        # spectro_y.append(data.brad)
        print(spectro_pointer)
        
        spectro_y[spectro_pointer] = data.brad
        spectro_pointer+= 1
    else:
        spectro_pointer = 0
        spectro_plot()

def ml_callback(data):
    ml_vid_obj = CvBridge()
    converted = ml_vid_obj.imgmsg_to_cv2(data)
    resized = cv2.resize(converted, (960, 640))  # Resize the image as needed
    image = cv2.cvtColor(resized, cv2.COLOR_BGR2RGB)
    img = Image.fromarray(image)
    imgtk = ImageTk.PhotoImage(image=img)
    vid_label.imgtk = imgtk
    vid_label.config(image=imgtk)

def ml_text_callback(data):
    text_label.config(text=data.data)

def ros_thread():
    '''
    Separate thread for ros with all publishers and subscribers
    '''
    # Publishers
    global flag_pub
    flag_pub = node.create_publisher(Int8, queue_size=1, "/flag_topic")
    
    # Subscribers
    node.create_subscription(atmos_msg, "/atmos_topic", atmos_callback)
    node.create_subscription(sensor_msg, "/sensor_topic", sensor_callback)
    node.create_subscription(spectro_msg, "/spectrometer", spectro_callback)
    node.create_subscription(RosImage, "/camera/image_raw", ml_callback)
    node.create_subscription(String, "/ml", ml_text_callback)
    
    rospy.spin()

def close_func():
    exit()


# frontend functions

def atmos_rec_plot():
    ax6.clear()
    ax7.clear()
    ax8.clear()
    
    ax6.plot(atmos_x, temp_y, 'b^-')
    ax6.set_title('Temperature plot')
    ax6.set_xlabel('time')
    ax6.set_ylabel('*C')

    ax7.plot(atmos_x, humidity_y, 'r^-')
    ax7.set_title('Humidity plot')
    ax7.set_xlabel('time')
    ax7.set_ylabel('%')
    
    ax8.plot(atmos_x, pressure_y, 'g^-')
    ax8.set_title('Pressure plot')
    ax8.set_xlabel('time')
    ax8.set_ylabel('hPa')

def atmos_plot():
    '''
    Plots the received sensor readings
    '''
    global atmos_start
    if len(atmos_x)==0:
        atmos_start = datetime.now()
        atmos_x.append(0)
    else:
        # atmos_x.append(round((datetime.now() - atmos_start).total_seconds()))
        atmos_x.append(((datetime.now() - atmos_start).total_seconds()))
    
    atmos_rec_plot()
    
    canvas_atmos.draw_idle()

def sensor_rec_plot():
    '''
    Clears previous plot and names the axes for sensors readings
    '''
    ax1.clear()
    ax2.clear()
    ax3.clear()
    
    ax1.plot(sensor_x, co2_y, 'b^-')
    ax1.set_title('CO2 plot')
    ax1.set_xlabel('time')
    ax1.set_ylabel('ppm')

    ax2.plot(sensor_x, ch4_y, 'r^-')
    ax2.set_title('CH4 plot')
    ax2.set_xlabel('time')
    ax2.set_ylabel('ppm')

    ax3.plot(sensor_x, co_y, 'g^-')
    ax3.set_title('CO plot')
    ax3.set_xlabel('time')
    ax3.set_ylabel('ppm')

def sensor_plot():
    '''
    Plots the received sensor readings
    '''
    global sensor_start
    if len(sensor_x)==0:
        sensor_start = datetime.now()
        sensor_x.append(0)
    else:
        # sensor_x.append(round((datetime.now() - sensor_start).total_seconds()))
        sensor_x.append(((datetime.now() - sensor_start).total_seconds()))
    
    sensor_rec_plot()
    
    canvas_sensor.draw_idle()
    
def spectro_rec_plot():
    '''
    Clears previous plot and names the axes for spectrometer readings
    '''
    # global spectro_time
    # if (spectro_time-datetime.now()).total_seconds > 1:
    #     spectro_y.clear()
    #     spectro_time = datetime.now()
    
    ax4.clear()
    # print(spectro_x, spectro_y, kmno4_y)
    ax4.plot(spectro_x, spectro_y, 'b^-')
    # ax4.set_title('Bradford assay')
    ax4.set_xlabel('wavelength')
    ax4.set_ylabel('absorbance')
    

def spectro_plot():
    '''
    Plots the received spectrometer readings
    '''
    # global spectro_start
    # if len(spectro_x)==0:
    #     spectro_start = datetime.now()
    #     spectro_x.append(0)
    # else:
    #     spectro_x.append((datetime.now() - spectro_start).total_seconds())
    
    spectro_rec_plot()
    
    canvas_spectro.draw_idle()
    
    # spectro_y.clear()
    # kmno4_y.clear()

# save buttons
def atmos_save():
    file_path = filedialog.asksaveasfilename()
    if file_path:
        with open(file_path, mode='w', newline='') as csv_file:
            print(temp_y, len(temp_y))
            print(humidity_y, len(humidity_y))
            print(pressure_y, len(pressure_y))
            writer = csv.writer(csv_file)
            writer.writerow(spectro_x)
            writer.writerow(temp_y)
            writer.writerow(humidity_y)
            writer.writerow(pressure_y)
    
    atmos_rec_plot()
    canvas_atmos.draw_idle()

    messagebox.showinfo(f"Save info", "Your file has been saved")

def sensor_save():
    file_path = filedialog.asksaveasfilename()
    if file_path:
        with open(file_path, mode='w', newline='') as csv_file:
            writer = csv.writer(csv_file)
            writer.writerow(sensor_x)
            writer.writerow(co2_y)
            writer.writerow(ch4_y)
            writer.writerow(co_y)
            
    sensor_x.clear()
    co2_y.clear()
    ch4_y.clear()
    co_y.clear()
    
    sensor_rec_plot()
    canvas_sensor.draw_idle()

    messagebox.showinfo(f"Save info", "Your file has been saved")

def spectro_save():
    file_path = filedialog.asksaveasfilename()            
    if file_path:
        file_exists = os.path.exists(file_path)

        with open(file_path, mode='a', newline='') as csv_file:
            writer = csv.writer(csv_file)
            if not file_exists:
                writer.writerow(spectro_x)

            writer.writerow(spectro_y)

            
    # spectro_x.clear()
    # spectro_y.clear()
    # kmno4_y.clear()
    
    spectro_rec_plot()
    canvas_spectro.draw_idle()

    messagebox.showinfo(f"Save info", "Your file has been saved")

# button click functions
def atmos_button_click():
    flag_pub.publish(6)

def sensor_button_click():
    flag_pub.publish(1)

def spectro_button_click():
    flag_pub.publish(2)

def ml_button_click():
    flag_pub.publish(3)

def panorama_button_click():
    flag_pub.publish(4)

def digi_button_click():
    flag_pub.publish(5)




def vid_feed_click_1():
    global feed_state_1, terminator_process_1

    if feed_state_1:
        feed_state_1 = 0
        terminator_process_1 = subprocess.Popen([f'/home/{user}/kratos_urc22/src/irc2024/gui/tkinter_GUI/bash/camfeed1.sh'])
    else:
        try:
            feed_state_1 = 1
            if terminator_process_1 is not None:
                terminator_process_1 = subprocess.Popen([f'/home/{user}/kratos_urc22/src/irc2024/gui/tkinter_GUI/bash/camfeed1_close.sh'])
        except subprocess.CalledProcessError:
            pass


def vid_feed_click_2():
    global feed_state_2, terminator_process_2
    

    if feed_state_2:
        feed_state_2 = 0
        terminator_process_2 = subprocess.Popen([f'/home/{user}/kratos_urc22/src/irc2024/gui/tkinter_GUI/bash/camfeed2.sh'])
    else:
        try:
            feed_state_2 = 1
            if terminator_process_2 is not None:
                terminator_process_2 = subprocess.Popen([f'/home/{user}/kratos_urc22/src/irc2024/gui/tkinter_GUI/bash/camfeed2_close.sh'])
        except subprocess.CalledProcessError:
            pass

def vid_feed_click_3():
    global feed_state_3, terminator_process_3

    if feed_state_3:
        feed_state_3 = 0
        terminator_process_3 = subprocess.Popen([f'/home/{user}/kratos_urc22/src/irc2024/gui/tkinter_GUI/bash/camfeed3.sh'])
    else:
        try:
            feed_state_3 = 1
            if terminator_process_3 is not None:
                terminator_process_3 = subprocess.Popen([f'/home/{user}/kratos_urc22/src/irc2024/gui/tkinter_GUI/bash/camfeed3_close.sh'])
        except subprocess.CalledProcessError:
            pass
def vid_feed_click_new():
    global feed_state_new, terminator_process_new

    if feed_state_new:
        feed_state_new = 0
        terminator_process_new = subprocess.Popen([f'/home/{user}/kratos_urc22/src/irc2024/gui/tkinter_GUI/bash/camlaunch.sh'])
    else:
        try:
            feed_state_new = 1
            if terminator_process_new is not None:
                terminator_process_new = subprocess.Popen([f'/home/{user}/kratos_urc22/src/irc2024/gui/tkinter_GUI/bash/camlaunchclose.sh'])
        except subprocess.CalledProcessError:
            pass

# main program
rospy.init_node("LD_gui", anonymous=True)

# Set daemon as parameter as True
ros_t = threading.Thread(target=ros_thread, daemon=True)
ros_t.start()

# root window definition
main_win = tk.Tk()
main_win.title('PROJECT KRATOS')
# main_win.geometry('1600x900')

style.use("ggplot")

main_win.protocol('WM_DELETE_WINDOW', close_func)

# Create different tabs and add titles
main_note = ttk.Notebook(main_win)

note_LD = ttk.Notebook(main_note)
note_controls = ttk.Notebook(main_note)

main_note.add(note_LD, text="LD tab")
main_note.add(note_controls, text="Controls tab")

main_note.pack(expand=True, fill='both')

# LD gui
atmos = tk.Frame(note_LD)
sensors = tk.Frame(note_LD)
spectro = tk.Frame(note_LD)
ml_box = tk.Frame(note_LD)
panorama = tk.Frame(note_LD)
digi_micro = tk.Frame(note_LD)

note_LD.add(atmos, text="Atmosphere")
note_LD.add(sensors, text="Sensor readings")
note_LD.add(spectro, text="Spectrometer")
note_LD.add(ml_box, text="ML box")
note_LD.add(panorama, text="Panorama")
note_LD.add(digi_micro, text="Digital Microscope")

# atmosphere window
atmos_fig, (ax6, ax7, ax8) = plt.subplots(1, 3, figsize=(16, 4))

atmos_rec_plot()

canvas_atmos = FigureCanvasTkAgg(figure=atmos_fig, master=atmos)
canvas_atmos.draw_idle()
canvas_atmos.get_tk_widget().pack(padx=35, pady=35)

atmos_button = tk.Button(master=atmos, text='Publish trigger', command=atmos_button_click)
atmos_button.pack(padx=15, pady=25)

save_atmos = tk.Button(master=atmos, text="Save values", command=atmos_save)
save_atmos.pack(padx=15, pady=25)

# sensor window
sensor_fig, (ax1, ax2, ax3) = plt.subplots(1, 3, figsize=(16, 4))

sensor_rec_plot()

canvas_sensor = FigureCanvasTkAgg(figure=sensor_fig, master=sensors)
canvas_sensor.draw_idle()
canvas_sensor.get_tk_widget().pack(padx=35, pady=35)

sensor_button = tk.Button(master=sensors, text='Publish trigger', command=sensor_button_click)
sensor_button.pack(padx=15, pady=25)

save_sensor = tk.Button(master=sensors, text="Save values", command=sensor_save)
save_sensor.pack(padx=15, pady=25)

# spectro window
spectro_fig, (ax4) = plt.subplots(1, 1, figsize=(16, 4))

spectro_rec_plot()

canvas_spectro = FigureCanvasTkAgg(figure=spectro_fig, master=spectro)
canvas_spectro.draw_idle()
canvas_spectro.get_tk_widget().pack(padx=35, pady=35)

spectro_button = tk.Button(master=spectro, text='Publish trigger', command=spectro_button_click)
spectro_button.pack(padx=15, pady=25)

save_spectro = tk.Button(master=spectro, text="Save values", command=spectro_save)
save_spectro.pack(padx=15, pady=25)

# ml window
vid_label = tk.Label(ml_box)
vid_label.pack(padx=15, pady=25, side='left')

text_label = tk.Label(ml_box, text="Loading...")
text_label.pack(padx=15, pady=25)

ml_button = tk.Button(master=ml_box, text='Publish trigger', command=ml_button_click)
ml_button.pack(padx=15, pady=25)

# panorama window
panorama_button = tk.Button(master=panorama, text='Publish trigger', command=panorama_button_click)
panorama_button.pack(padx=15, pady=25)

# digital microscope window
digi_button = tk.Button(master=digi_micro, text='Publish trigger', command=digi_button_click)
digi_button.pack(padx=15, pady=25)

# Controls gui
# camera feeds
vid_feed = tk.Frame(note_controls)

note_controls.add(vid_feed, text="Video feeds")

feed_frame_1 = tk.Frame(vid_feed)
feed_frame_2 = tk.Frame(vid_feed)
feed_frame_3 = tk.Frame(vid_feed)
feed_frame_new = tk.Frame(vid_feed)

feed_frame_1.pack()
feed_frame_2.pack()
feed_frame_3.pack()
feed_frame_new.pack()

feed_state_1 = 1
feed_state_2 = 1
feed_state_3 = 1
feed_state_new=1

feed_but_1 = tk.Button(master=feed_frame_1, text="Feed 1", command=vid_feed_click_1)
feed_but_2 = tk.Button(master=feed_frame_2, text="Feed 2", command=vid_feed_click_2)
feed_but_3 = tk.Button(master=feed_frame_3, text="Feed 3", command=vid_feed_click_3)
feed_but_new = tk.Button(master=feed_frame_new, text="New Feed", command=vid_feed_click_new)

feed_but_1.pack(padx=25, pady=25)
feed_but_2.pack(padx=25, pady=25)
feed_but_3.pack(padx=25, pady=25)
feed_but_new.pack(padx=25, pady=25)

plt.tight_layout()


main_win.mainloop()

