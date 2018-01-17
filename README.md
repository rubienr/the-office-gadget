# The Office Gadget
A very simple tool to visualize things having

* wifi,
* web service,
* display,
* touch keyboard,
* temperature sensor,
* light sensor and
* serial interfaced RGB LED strips.

<p align="center">
  <img src="https://github.com/rubienr/the_office_gadget/blob/master/docs/tog.jpg?raw=true" width="350"/>
</p>

# Start Working
```
git clone https://github.com/rubienr/the_office_gadget.git
cd the_office_gadget/src/
platformio init --ide clion
```
Then: Clion -> open project -> navigate to `the_office_gadget/src/` -> open.

# Install Platformio
```
python -c "$(curl -fsSL https://raw.githubusercontent.com/platformio/platformio/develop/scripts/get-platformio.py)"
pio upgrade --dev
```
[See also http://docs.platformio.org/...](http://docs.platformio.org/en/latest/installation.html#installer-script)
