as yet unclassified
additionsToViewerCategories
^ #(
(#'pic - connection' (
#(command connect 'Connects this device' )
#(command disconnect 'Disconnects this device' )
#(slot isConnected 'Shows if the device is connected' Boolean readOnly Player getIsConnected Player unused )
))

(#'pic - port a' (
#(slot #'ra0' 'Accesses the current value of the pin' Number readWrite Player getRA0 Player setRA0: )
#(slot #'ra1' 'Accesses the current value of the pin' Number readWrite Player getRA1 Player setRA1: )
#(slot #'ra2' 'Accesses the current value of the pin' Number readWrite Player getRA2 Player setRA2: )
#(slot #'ra3' 'Accesses the current value of the pin' Number readWrite Player getRA3 Player setRA3: )
#(slot #'ra4' 'Accesses the current value of the pin' Boolean readWrite Player getRA4 Player setRA4: )
#(slot #'ra5' 'Accesses the current value of the pin' Number readWrite Player getRA5 Player setRA5: )
))

(#'pic - port b' (
#(slot #'rb0' 'Accesses the current value of the pin' Number readWrite Player getRB0 Player setRB0: )
#(slot #'rb1' 'Accesses the current value of the pin' Number readWrite Player getRB1 Player setRB1: )
#(slot #'rb2' 'Accesses the current value of the pin' Number readWrite Player getRB2 Player setRB2: )
#(slot #'rb3' 'Accesses the current value of the pin' Number readWrite Player getRB3 Player setRB3: )
#(slot #'rb4' 'Accesses the current value of the pin' Number readWrite Player getRB4 Player setRB4: )
#(slot #'rb5' 'Accesses the current value of the pin' Boolean readWrite Player getRB5 Player setRB5: )
#(slot #'rb6' 'Accesses the current value of the pin' Boolean readWrite Player getRB6 Player setRB6: )
#(slot #'rb7' 'Accesses the current value of the pin' Boolean readWrite Player getRB7 Player setRB7: )
))

(#'pic - port d' (
#(slot #'rd0' 'Accesses the current value of the pin' Boolean readWrite Player getRD0 Player setRD0: )
#(slot #'rd1' 'Accesses the current value of the pin' Boolean readWrite Player getRD1 Player setRD1: )
#(slot #'rd2' 'Accesses the current value of the pin' Boolean readWrite Player getRD2 Player setRD2: )
#(slot #'rd3' 'Accesses the current value of the pin' Boolean readWrite Player getRD3 Player setRD3: )
#(slot #'rd4' 'Accesses the current value of the pin' Boolean readWrite Player getRD4 Player setRD4: )
#(slot #'rd5' 'Accesses the current value of the pin' Boolean readWrite Player getRD5 Player setRD5: )
#(slot #'rd6' 'Accesses the current value of the pin' Boolean readWrite Player getRD6 Player setRD6: )
#(slot #'rd7' 'Accesses the current value of the pin' Boolean readWrite Player getRD7 Player setRD7: )
))


(#'pic - port a mode' (
#(slot #'ra0Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRA0Mode Player setRA0Mode: )
#(slot #'ra1Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRA1Mode Player setRA1Mode: )
#(slot #'ra2Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRA2Mode Player setRA2Mode: )
#(slot #'ra3Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRA3Mode Player setRA3Mode: )
#(slot #'ra4Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRA4Mode Player setRA4Mode: )
#(slot #'ra5Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRA5Mode Player setRA5Mode: )
))

(#'pic - port b mode' (
#(slot #'rb0Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRB0Mode Player setRB0Mode: )
#(slot #'rb1Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRB1Mode Player setRB1Mode: )
#(slot #'rb2Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRB2Mode Player setRB2Mode: )
#(slot #'rb3Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRB3Mode Player setRB3Mode: )
#(slot #'rb4Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRB4Mode Player setRB4Mode: )
#(slot #'rb5Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRB5Mode Player setRB5Mode: )
#(slot #'rb6Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRB6Mode Player setRB6Mode: )
#(slot #'rb7Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRB7Mode Player setRB7Mode: )
))

(#'pic - port d mode' (
#(slot #'rd0Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRD0Mode Player setRD0Mode: )
#(slot #'rd1Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRD1Mode Player setRD1Mode: )
#(slot #'rd2Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRD2Mode Player setRD2Mode: )
#(slot #'rd3Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRD3Mode Player setRD3Mode: )
#(slot #'rd4Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRD4Mode Player setRD4Mode: )
#(slot #'rd5Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRD5Mode Player setRD5Mode: )
#(slot #'rd6Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRD6Mode Player setRD6Mode: )
#(slot #'rd7Mode' 'Lets you modify the mode (INPUT/OUTPUT) of the pin' PICPinMode readWrite Player getRD7Mode Player setRD7Mode: )
))
)