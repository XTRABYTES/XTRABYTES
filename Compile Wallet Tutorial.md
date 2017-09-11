---
# XTRABYTES Qt Wallet GUI Compilation Guide
---

## Building the XTRABYTES wallet on Ubuntu/Debian

This is a guide for compiling the XTRABYTES wallet using Linux. By following this guide, you will be able to create a GUI wallet directly from the source code.

## Requirements

The basic requirements for wallet compilation:

```
Linux (Ubuntu or Debian-based distribution is prefered but any other Linux distro can be used)

32 or 64-bit
```

It is recommended to have at least 1 GB of memory available when compiling the XTRABYTES wallet. 
Compilation will take much longer with 512 MB of memory or less.

## Getting started

You need to make sure your Linux machine is up to date. 
Open a terminal window by clicking the right side mouse button and choosing Open Terminal while in the Desktop.

![Image](https://github.com/borzalom/XtraBYtes/blob/master/etc/images/1terminal.png?raw=true)

In the terminal window type:

```
sudo apt-get update (press Y to update)

sudo apt-get upgrade (press Y to upgrade)
```

![Image](https://github.com/borzalom/XtraBYtes/blob/master/etc/images/1sudopass.png?raw=true)

**Note**: Every time you issue a command using **sudo**, it will ask you for your password. It will not be visible while you type it. Press enter once you finish typing it.

It might take a few minutes to update/upgrade.

## Install the dependency packages

Sometimes it is necessary to install extra libraries and dependency packages or simply to update them.
Using the terminal window, type:

```
sudo apt-get install qt5-default qt5-qmake qtbase5-dev-tools qttools5-dev-tools build-essential libssl-dev libdb++-dev libboost-all-dev libqrencode-dev libminiupnpc-dev
```

Accept any installation or update prompt by pressing the Y key.

## Download the XTRABYTES source code

You can download the source code directly to your Desktop. It will automatically create a xtrabytes folder.

```
cd Desktop

git clone https://github.com/borzalom/xtrabytes.git
```

![Image](https://github.com/borzalom/XtraBYtes/blob/master/etc/images/1gitclone.png?raw=true)

## Final stage - Compilation

You are now ready to compile the wallet. You need to enter the directory where the source code was copied to, in this case the xtrabytes folder:

```
cd xtrabytes
```

Execute this command:

```
qmake xtrabytes-qt.pro
```

![Image](https://github.com/borzalom/XtraBYtes/blob/master/etc/images/1qmake.png?raw=true)

And:

```
make -f Makefile
```

You will see something like this being displayed. Wait until the process is finished.

![Image](https://github.com/borzalom/XtraBYtes/blob/master/etc/images/1xtramake1.png?raw=true)

Once the wallet has been successfully compiled, you will be able to run it.

***


#### An alternate way to compile the wallet

This is an alternate way to compile the wallet. Follow all the above steps but instead of typing **qmake xtrabytes-qt.pro** and **make -f Makefile**, use the following command:

```
qmake && make
```

![Image](https://github.com/borzalom/XtraBYtes/blob/master/etc/images/1qmake1.png?raw=true)


Once it is done type:

```
chmod +x xtrabytes-qt 
```

![Image](https://github.com/borzalom/XtraBYtes/blob/master/etc/images/1chmod1.png?raw=true)

**Note**: Though not necessary, this command makes the file executable.

***

## Running the wallet

To run the wallet simply type:

```
./xtrabytes-qt
```

![Image](https://github.com/borzalom/XtraBYtes/blob/master/etc/images/1wallet2.png?raw=true)

You now have a fully functional wallet. Enjoy!

![Image](https://github.com/borzalom/XtraBYtes/blob/master/etc/images/1wallet.png?raw=true)

## XTRABYTES social links:

FACEBOOK - https://www.facebook.com/XTRABYTESOfficial/

TWITTER - https://twitter.com/xtrabytes

REDDIT - https://www.reddit.com/r/xtrabytes

YOUTUBE - https://www.youtube.com/c/XTRABYTESOFFICIAL

STEEM - https://steemit.com/@xtrabytes

MEDIUM - https://medium.com/@XTRABYTES

INSTAGRAM - https://www.instagram.com/xtrabytes

VIMEO - https://vimeo.com/xtrabytes

SLACK - https://xtrabytes.herokuapp.com

***

Version 1.0
