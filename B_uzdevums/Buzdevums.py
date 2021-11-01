def garaisyyyy(yyyy):
    if (yyyy % 4 ==0):
        if (yyyy % 100 == 0 and yyyy % 400 != 0):
            return False
        else:
            return True
    else:
        return False


def nedelasdiena(dd,mm,yyyy):
    t = [ 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 ]
    yyyy -= mm < 3
    return int((yyyy + int(yyyy / 4) - int (yyyy / 100) + int(yyyy / 400) + t[mm - 1] + dd) % 7)

while True:
    diena = ["Svetdiena","Pirmdiena","Otrdiena","Tresdiena","Ceturtdiena","Piektdiena","Sestdiena"]
    
    dd = int(input("Ievadi dienu "))
    if (dd>31 or dd<0):
        print("Nepareizs datums")
        dd = int(input("Ievadi dienu "))
    
    mm = int(input("Ievadi mēnesi "))
    if (mm>12 or mm<0):
        print("Nepareizs mēnesis")
        mm = int(input("Ievadi mēnesi "))    
    
    yyyy = int(input("Ievadi gadu "))
    if (yyyy<0):
        print("Nepareizs gads")
        yyyy = int(input("Ievadi gadu "))
    
    neddd = nedelasdiena(dd,mm,yyyy)
    print(diena[neddd])
    
    if (garaisyyyy == True):
        print("Šis ir garais gads")
    else:
        print("Šis ir īsais gads")

    while True:
        answer = str(input('Atkartot programmu? (1/0:)' ))
        if answer in ('1', '0'):
            break
        print("Error")
    
    if answer == '1':
        continue
    else: 
        break