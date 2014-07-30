viewer categories
additionsToViewerCategories
^ #(
(#'mendieta - connection' (
#(command connect 'Connects this device' )
#(command disconnect 'Disconnects this device' )
#(slot isConnected 'Shows if the device is connected' Boolean readOnly Player getIsConnected Player unused )
))


(#'mendieta - digital pins' (
#(slot #'digitalPin 1' 'Accesses the current digital value of the pin' Boolean readWrite Player getDigitalPin1 Player setDigitalPin1: )
#(slot #'digitalPin 2' 'Accesses the current digital value of the pin' Boolean readWrite Player getDigitalPin2 Player setDigitalPin2: )
#(slot #'digitalPin 3' 'Accesses the current digital value of the pin' Boolean readWrite Player getDigitalPin3 Player setDigitalPin3: )
#(slot #'digitalPin 4' 'Accesses the current digital value of the pin' Boolean readWrite Player getDigitalPin4 Player setDigitalPin4: )
#(slot #'digitalPin 5' 'Accesses the current digital value of the pin' Boolean readWrite Player getDigitalPin5 Player setDigitalPin5: )
))


(#'mendieta - digital pins mode' (

#(slot #'digitalPin 1Mode' 'Indicates if the pin is in output/input mode' ArduinoPinMode readWrite Player getDigitalPin1Mode Player setDigitalPin1Mode:  )
#(slot #'digitalPin 2Mode' 'Indicates if the pin is in output/input mode' ArduinoPinMode readWrite Player getDigitalPin2Mode Player setDigitalPin2Mode:  )
#(slot #'digitalPin 3Mode' 'Indicates if the pin is in output/input mode' ArduinoPinMode readWrite Player getDigitalPin3Mode Player setDigitalPin3Mode:  )
#(slot #'digitalPin 4Mode' 'Indicates if the pin is in output/input mode' ArduinoPinMode readWrite Player getDigitalPin4Mode Player setDigitalPin4Mode:  )
#(slot #'digitalPin 5Mode' 'Indicates if the pin is in output/input mode' ArduinoPinMode readWrite Player getDigitalPin5Mode Player setDigitalPin5Mode:  )
))

)