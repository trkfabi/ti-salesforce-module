package com.inzori.salesforcechat;

import org.appcelerator.kroll.KrollModule;
import org.appcelerator.kroll.annotations.Kroll;
import org.appcelerator.kroll.KrollDict;
import org.appcelerator.kroll.KrollFunction;
import org.appcelerator.kroll.KrollProxy;
import org.appcelerator.kroll.common.Log;
import com.salesforce.android.chat.core.SessionInfoListener;
import com.salesforce.android.chat.core.model.ChatSessionInfo;

public class MySessionInfoListener extends KrollModule implements SessionInfoListener {
    private static final String LCAT = "SalesforceChatModule - MySessionInfoListener";

    public void onSessionInfoReceived (ChatSessionInfo chatSessionInfo) {
        Log.w(LCAT, "session info: " + chatSessionInfo.toString());
        // TO DO: Do something with the session ID
        String sessionId = chatSessionInfo.getSessionId();
        KrollDict eventData = new KrollDict();
        eventData.put("sessionId",sessionId);   
        fireEvent("salesforce_chat:session_info", eventData);         
    }
   
}