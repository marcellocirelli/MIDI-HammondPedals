# MIDI Hammond Pedals

A full **12-key MIDI foot controller** built using vintage **Hammond M3 bass pedals**, designed for expressive, hands-free control in live performance and studio use.
![IMG_2283](https://github.com/user-attachments/assets/994a171a-f25e-4947-877d-70fcfcf7be30)
This project combines hardware modification, embedded programming, and MIDI control to create a flexible pedalboard capable of note input, parameter control, and effects triggering.

## Overview

This controller was built after completing a Hammond M3 organ “chop” and repurposing the original pedal assembly into a modern MIDI device.  
The goal was to retain the physical feel and ergonomics of the Hammond pedals while extending their functionality far beyond traditional bass note triggering.

The system supports musical note input as well as continuous and momentary control for synthesis, effects, and DAW interaction.

## Features

- **12-key MIDI note controller**
  - Each pedal sends configurable MIDI note messages
- **Expression pedal**
  - Continuous control (e.g. volume, filter cutoff, modulation)
- **Sustain pedal**
  - Standard MIDI sustain behavior
- **Three momentary stomp switches**
  - Trigger samples, effects, or program changes
- **Program change support**
- **Velocity / control mapping flexibility**
- Designed for **live performance reliability**

## Hardware Components

- Vintage **Hammond M3 bass pedal assembly**
- Expression pedal
- Sustain pedal
- Three momentary footswitches
- Microcontroller-based MIDI interface (Adafruit ItsyBitsy 32u4)
- Custom wiring harness and signal conditioning
- Enclosure design (CAD included in repository)

## Software / Firmware

- Embedded firmware handles:
  - Pedal scanning
  - Debouncing
  - MIDI message generation
  - Control change and program change logic
  - USB MIDI class compliance
- Modular design to allow reassignment of pedals and controls
- Compatible with standard USB MIDI hardware, DAWs, and software instruments

## MIDI Capabilities

The controller can send:
- MIDI Note On / Off
- Control Change (CC)
- Program Change
- Sustain (CC 64)
- Continuous expression data

This allows the unit to function as:
- A bass note controller
- An effects control surface
- A DAW transport or automation controller
- A hybrid performance tool

## Enclosure Design

The repository includes **CAD drawings** (Sketchup Pro) for a custom enclosure intended for:
- On-stage durability
- Secure mounting of pedals and electronics
- Clean cable routing
- Future expandability

The enclosure is still under active development.

## Technologies Used

- Embedded C / C++
- MIDI protocol
- Microcontroller development (Arduino Libraries)
- Hardware interfacing and debouncing
- CAD for enclosure design (Sketchup Pro)
- Music performance hardware design

## Purpose

This project demonstrates:
- Practical embedded systems development
- Hardware–software integration
- MIDI protocol implementation
- Real-world music technology problem solving
- Design for live performance reliability

## Status

- Core functionality complete and usable
- Enclosure design in progress

## Notes

This project was developed independently as a personal music technology build and is included as a portfolio example of embedded programming, hardware design, and applied audio technology.
