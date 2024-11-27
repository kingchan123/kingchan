def nextClk():
    global num
    num = num + 1
    if num > 4:
        num = 0
    photo = PhotoImage(file='gif/' + fileList[num])
    pLabel.image = photo
    pLabel.config(image=photo)
    fileLabel.config(text=fileList[num])

def prevClk():
    global num
    num = num - 1
    if num < 0:
        num = 4
    photo = PhotoImage(file='gif/' + fileList[num])
    pLabel.image = photo
    pLabel.config(image=photo)
    fileLabel.config(text=fileList[num])

photo = PhotoImage(file='gif/' + fileList[0])
pLabel = Label(w, image=photo)
pLabel.place(x=20, y=40)

fileLabel = Label(w, text=fileList[0])
fileLabel.place(x=320, y=10)

rightBtn = Button(w, text='>', command=nextClk)
rightBtn.place(x=350 + 175, y=10)

leftBtn = Button(w, text='<', command=prevClk)
leftBtn.place(x=350, y=10)
