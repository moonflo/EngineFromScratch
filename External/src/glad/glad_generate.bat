pip install glad
python -m glad --generator=c --api="gl=4.6" --spec gl --out-path=.
python -m glad --generator=c --api="wgl=1.0" --spec wgl --out-path=.
python -m glad --generator=c --api="glx=1.4" --spec glx --out-path=.
pause
