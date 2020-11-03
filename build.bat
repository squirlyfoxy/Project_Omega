@echo off

cd pys
py build_all.py

if "%1" == "iso" (
	py build_iso.py
)