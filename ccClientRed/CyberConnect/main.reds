// public native class MyCustomClass extends IScriptable {
//     public native func GetNumber(worldPosition: Vector4, count: Int32) -> Float
//     //public native func ConnectionIsConnected() -> Bool;
//     public native func ConnectionConnect(ip: String, port: Int32)-> Bool
//     //ublic native func ConnectionDisconnect() -> Bool;
//     //public native func ConnectionSend(message: String) -> String;
//     //public native func ConnectionReceive() -> String;
// }

public static native func ConnectionConnect(ip: String, port: Int32)-> Bool
public static native func ConnectionIsConnected()-> Bool

public static native func ConnectionReceive()-> String


public final func startConnect(ip: String, port: Int32) {
    let isConnected = false;
    isConnected = ConnectionConnect("127.0.0.1", 2077);

    // if (isConnected)
    // {
    //    while(true)
    //    {
    //     let rec = "";
    //     rec = ConnectionReceive();
    //     Log(rec);
    //     //sleep(0);
    //    }
    // }
}

// public final func receivePacket(packet: String) {
//     Log(packet)
// }
