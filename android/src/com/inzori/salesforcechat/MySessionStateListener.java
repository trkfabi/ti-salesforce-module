package com.inzori.salesforcechat;

import org.appcelerator.titanium.TiApplication;
import android.app.Activity;
import android.content.Context;

import org.appcelerator.kroll.KrollModule;
import org.appcelerator.kroll.annotations.Kroll;
import org.appcelerator.kroll.KrollDict;
import org.appcelerator.kroll.KrollFunction;
import org.appcelerator.kroll.KrollProxy;

import org.appcelerator.kroll.common.Log;
import com.salesforce.android.chat.core.SessionStateListener;
import com.salesforce.android.chat.core.model.ChatSessionState;
import com.salesforce.android.chat.core.model.ChatEndReason;

public class MySessionStateListener extends KrollModule implements SessionStateListener{
  private static final String LCAT = "SalesforceChatModule - MySessionStateListener";

  @Override public void onSessionStateChange (ChatSessionState state) {
    String stateName = "UNKNOWN";
    Log.w(LCAT, "session state: " + state.toString());

    if (state == ChatSessionState.Ready) {
      // TODO: Handle the disconnected state change
      stateName = "READY";
    }
    if (state == ChatSessionState.Verification) {
      // TODO: Handle the disconnected state change
      stateName = "VERIFICATION";
    }    
    if (state == ChatSessionState.Initializing) {
      // TODO: Handle the disconnected state change
      stateName = "INITIALIZING";
    }    
    if (state == ChatSessionState.Connecting) {
      // TODO: Handle the disconnected state change
      stateName = "CONNECTING";
    }    
    if (state == ChatSessionState.InQueue) {
      // TODO: Handle the disconnected state change
      stateName = "INQUEUE";
    }    
    if (state == ChatSessionState.Connected) {
      // TODO: Handle the disconnected state change
      stateName = "CONNECTED";
    }    
    if (state == ChatSessionState.Ending) {
      // TODO: Handle the disconnected state change
      stateName = "ENDING";
    }    
    if (state == ChatSessionState.Disconnected) {
      // TODO: Handle the disconnected state change
      stateName = "DISCONNECTED";
    } 

    KrollDict eventData = new KrollDict();
    eventData.put("state",stateName);   
    fireEvent("salesforce_chat:session_state", eventData);    
  }

  @Override public void onSessionEnded (ChatEndReason endReason) {
    Log.w(LCAT, "session end reason: " + endReason.toString());
    String reasonName = "UNKNOWN";

    if (endReason == ChatEndReason.EndedByAgent) {
      reasonName = "AGENT";
    }
    if (endReason == ChatEndReason.EndedByClient) {
      reasonName = "USER";
    }
    if (endReason == ChatEndReason.LiveAgentTimeout) {
      reasonName = "TIMEOUT";
    }
    if (endReason == ChatEndReason.NetworkError) {
      reasonName = "ERROR";
    }
    if (endReason == ChatEndReason.NoAgentsAvailable) {
      reasonName = "NOAGENTSAVAILABLE";
    }  
    if (endReason == ChatEndReason.VerificationError) {
      reasonName = "ERROR";
    }               
    KrollDict eventData = new KrollDict();
    eventData.put("reason",reasonName);   
    fireEvent("salesforce_chat:session_end", eventData);  
  }

}