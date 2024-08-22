#!/bin/bash
#ekremiscan

ips=10.1.10.25

for ip in "${ips[@]}"; do
        ssh -Tq $ip << 'EOF'
ssh -Tq scc
echo ""
last=$(ls -t1 /opt/eds/log/diag/trace/* | head -n 1)
last2=$(ls -t1 /opt/eds/log/diag/trace/* | head -n 2 | tail -n 1)
fsm=$(less /opt/eds/log/scs.log | grep 'FSM:input' | tail -n 1 | awk -F= '{print $2}')
log=$(less /opt/eds/log/scs.log.1 /opt/eds/log/scs.log.0 /opt/eds/log/scs.log | grep 'scs_fault_cause : state: '  | tail -n 1 | awk '{print $11}')
state=$(less $last2 $last | grep 'SCS state change:' | awk -F= '{print $2}' | awk -F'(' '{print $1}' | tail -n 1)
echo -e "State= $state"


if [[ $fsm == 'DiagMode(DesiredState' ]]; then
echo -e "State2= Diagnostic"
elif [[ $fsm == 'Dieback(DesiredState' ]]; then
echo -e "State2= Dieback"
elif [[ $fsm == 'WaitForSystemReadinessCheckDone(DesiredState' ]]; then
echo -e "State2= System Check"
elif [[ $fsm == 'ColdStandby(DesiredState' ]]; then
echo -e "State2= Cold Standby"
elif [[ $fsm == 'ScanUnblocked(DesiredState' ]]; then
echo -e "State2= Scan"
elif [[ $fsm == 'ScanBlocked(DesiredState' ]]; then
echo -e "State2= Scan"
fi

if [[ $log == '0' ]]; then
echo -e "Fault= None"
elif [[ $log == '1' ]]; then
echo -e "Fault= WaitingForDevices"
elif [[ $log == '2' ]]; then
echo -e "Fault= DevicesUninitialized"
elif [[ $log == '3' ]]; then
echo -e "Fault= KeyPowerOff"
elif [[ $log == '4' ]]; then
echo -e "Fault= SDB2_Fault"
elif [[ $log == '5' ]]; then
echo -e "Fault= BIT_Fault"
elif [[ $log == '6' ]]; then
echo -e "Fault= DIAG_Fault"
elif [[ $log == '7' ]]; then
echo -e "Fault= DIAG_POST_TIMEOUT"
elif [[ $log == '8' ]]; then
echo -e "Fault= SRC_FAILED"
elif [[ $log == '9' ]]; then
echo -e "Fault= ISHWFAULTCONDITION"
elif [[ $log == '10' ]]; then
echo -e "Fault= UserRequested"
elif [[ $log == '11' ]]; then
echo -e "Fault= SubSystemMissing"
elif [[ $log == '12' ]]; then
echo -e "Fault= PASSTHROUGH"
elif [[ $log == '13' ]]; then
echo -e "Fault= DCBOFFSET_FAILURE"
elif [[ $log == '14' ]]; then
echo -e "Fault= DARKCAL_REQUESTED"
elif [[ $log == '15' ]]; then
echo -e "Fault= ENCODERCNT_EXCEEDED"
elif [[ $log == '16' ]]; then
echo -e "Fault= E-STOP"
elif [[ $log == '17' ]]; then
echo -e "Fault= INTERLOCK"
elif [[ $log == '18' ]]; then
echo -e "Fault= HVPS_RAMPUP"
elif [[ $log == '19' ]]; then
echo -e "Fault= Standby"
elif [[ $log == '20' ]]; then
echo -e "Fault= Reboot"
elif [[ $log == '21' ]]; then
echo -e "Fault= WatchDog"
elif [[ $log == '22' ]]; then
echo -e "Fault= SYSTIC_FAULT"
elif [[ $log == '23' ]]; then
echo -e "Fault= ENCODER_FAULT"
elif [[ $log == '24' ]]; then
echo -e "Fault= LIGHT_CURTAIN_FAULT"
elif [[ $log == '25' ]]; then
echo -e "Fault= GALIL_FAULT"
elif [[ $log == '26' ]]; then
echo -e "Fault= Acuvim_Fault"
elif [[ $log == '27' ]]; then
echo -e "Fault= Yaskawa_Fault"
elif [[ $log == '28' ]]; then
echo -e "Fault= MFORCE_Fault"
elif [[ $log == '29' ]]; then
echo -e "Fault= MFORCE_Fault"
elif [[ $log == '30' ]]; then
echo -e "Fault= HVPS_Fault"
elif [[ $log == '31' ]]; then
echo -e "Fault= DCB_Fault"
elif [[ $log == '32' ]]; then
echo -e "Fault= System_Verify_Fault"
elif [[ $log == '33' ]]; then
echo -e "Fault= BMS_Entrance_Bag_Jam"
elif [[ $log == '34' ]]; then
echo -e "Fault= BMS_BHS_FAULT"
elif [[ $log == '35' ]]; then
echo -e "Fault= SYSTIC_TIMEOUT"
elif [[ $log == '36' ]]; then
echo -e "Fault= SDB2_TIMEOUT"
elif [[ $log == '37' ]]; then
echo -e "Fault= DCB_TIMEOUT"
elif [[ $log == '38' ]]; then
echo -e "Fault= DPP_RTR_DOWN"
elif [[ $log == '39' ]]; then
echo -e "Fault= BMS_RTR_DOWN"
elif [[ $log == '40' ]]; then
echo -e "Fault= IAC_RTR_DOWN"
elif [[ $log == '41' ]]; then
echo -e "Fault= DPP_OPSTATE_FAULT"
elif [[ $log == '42' ]]; then
echo -e "Fault= IAC_OPSTATE_FAULT"
elif [[ $log == '43' ]]; then
echo -e "Fault= INIT_TIMEOUT_FAULT"
elif [[ $log == '44' ]]; then
echo -e "Fault= SEASONING_FAILED"
elif [[ $log == '45' ]]; then
echo -e "Fault= Transients_Failed"
elif [[ $log == '46' ]]; then
echo -e "Fault= Array_Test_Failed"
elif [[ $log == '47' ]]; then
echo -e "Fault= BMS_SUBSYS_MISSING"
elif [[ $log == '48' ]]; then
echo -e "Fault= IAC_SUBSYS_MISSING"
elif [[ $log == '49' ]]; then
echo -e "Fault= DPP_SUBSYS_MISSING"
elif [[ $log == '50' ]]; then
echo -e "Fault= DIAGS_SUBSYS_MISSING"
elif [[ $log == '51' ]]; then
echo -e "Fault= PLC_Connection_Loss"
elif [[ $log == '52' ]]; then
echo -e "Fault= DPP_HIGH_WATERMARK"
elif [[ $log == '54' ]]; then
echo -e "Fault= CHILLER_FAULT"
fi
if [[ $log -gt '1' ]] && [[ $log -gt '2' ]]; then
echo -e "!!!!!!!!!"
fi
EOF
if [ $? -ne 0 ]; then
echo "Disconnected"
fi

echo ""
done
