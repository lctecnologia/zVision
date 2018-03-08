#!/bin/bash

echo ZTronics - Iniciando PLay Station Eye 3
echo By LC - Software

sudo modinfo gspca_ov534

echo Detectando informação da Play Eye

sleep 2


sudo modprobe -r gspca_ov534

echo Adicionando Play Eye ao Sistema

sleep 4

sudo modprobe gspca_ov534

sleep 3

echo Play Station Eye 3 - Iniciado !!!


