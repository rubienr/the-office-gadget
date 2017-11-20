## Prerequisites
### Required packages
* pip

### Install platformio

```
$ python -c "$(curl -fsSL https://raw.githubusercontent.com/platformio/platformio/develop/scripts/get-platformio.py)"
$ # ev. update/upgrade
$ sudo platformio upgrade
$ platformio update
```
* http://docs.platformio.org/en/latest/installation.html#super-quick-mac-linux


## Build
```
platformio run
```
* http://docs.platformio.org/en/latest/quickstart.html#process-project

## Install
```
platformio run --target upload
```
* http://docs.platformio.org/en/latest/quickstart.html#process-project

## Related Pages
* platformio
  * clion - http://docs.platformio.org/en/latest/ide/clion.html
  * cli - http://docs.platformio.org/en/latest/userguide/cmd_run.html#cmd-run
  * library deps - http://docs.platformio.org/en/latest/librarymanager/quickstart.html
* oled
  * example - http://www.instructables.com/id/Monochrome-096-i2c-OLED-display-with-arduino-SSD13/

## Initially Create Empty Project

```
$ platformio init --ide clion --board d1_mini

The current working directory /mnt/old-system/data/git/nightly-test-monitor will be used for project.
You can specify another project directory via
`platformio init -d %PATH_TO_THE_PROJECT_DIR%` command.

The next files/directories have been created in /mnt/old-system/data/git/nightly-test-monitor
platformio.ini - Project Configuration File
src - Put your source files here
lib - Put here project specific (private) libraries

Project has been successfully initialized!
Useful commands:
`platformio run` - process/build project from the current directory
`platformio run --target upload` or `platformio run -t upload` - upload firmware to embedded board
`platformio run --target clean` - clean project (remove compiled files)
`platformio run --help` - additional information
$
```
