package com.inzori.salesforcechat;

import org.appcelerator.kroll.KrollModule;
import org.appcelerator.kroll.annotations.Kroll;
import org.appcelerator.kroll.KrollDict;
import org.appcelerator.kroll.KrollFunction;
import org.appcelerator.kroll.KrollProxy;
import org.appcelerator.kroll.common.Log;

import com.salesforce.android.chat.ui.ChatEventListener;
import com.salesforce.android.chat.core.model.AgentInformation;

import com.salesforce.android.chat.core.model.ChatWindowMenu;
import com.salesforce.android.chat.core.model.ChatWindowMenu.MenuItem;
import com.salesforce.android.chat.core.model.ChatWindowButtonMenu.Button;
import com.salesforce.android.chat.core.model.ChatWindowButtonMenu;
import com.salesforce.android.chat.core.model.ChatWindowButtonMenu.Button;
import com.salesforce.android.chat.core.model.ChatMessage;
import com.salesforce.android.chat.core.model.ChatFooterMenu;

public class MyEventListener extends KrollModule implements ChatEventListener {
    private static final String LCAT = "SalesforceChatModule - MyEventListener";
    private static final String eventName = "salesforce_chat:session_event";

	public MyEventListener()
	{
		super();
	}
    
    public void agentJoined (AgentInformation agentInformation) {
        // Handle agent joined
        Log.w(LCAT, "agent: " + agentInformation.getAgentName() + " isBot: " + agentInformation.isChatBot());
        KrollDict eventData = new KrollDict();
        eventData.put("name", "AGENTJOINED");   
        eventData.put("data", agentInformation);
        super.fireEvent(eventName, eventData);         
    }

    public void processedOutgoingMessage (String message) {
        // Handle outgoing message processed
        Log.w(LCAT, "out message: " + message);
        KrollDict eventData = new KrollDict();
        eventData.put("name", "PROCESSEDOUTGOINGMESSAGE");   
        eventData.put("data", message);   
        fireEvent(eventName, eventData);         
    }

    public void didSelectMenuItem (ChatWindowMenu.MenuItem menuItem) {
        // Handle chatbot menu selected
        KrollDict eventData = new KrollDict();
        eventData.put("name", "ITEMSELECTED");    
        fireEvent(eventName, eventData);    
    }

    public void didSelectButtonItem (ChatWindowButtonMenu.Button buttonItem) {
        // Handle chatbot button selected
        KrollDict eventData = new KrollDict();
        eventData.put("name", "BUTTONSELECTED");    
        fireEvent(eventName, eventData);  
    }

    public void didSelectFooterMenuItem (ChatFooterMenu.MenuItem footerMenuItem) {
        // Handle chatboot footer menu selected
        KrollDict eventData = new KrollDict();
        eventData.put("name", "FOOTERITEMSELECTED");    
        fireEvent(eventName, eventData);  
    }

    public void didReceiveMessage (ChatMessage chatMessage) {
        Log.w(LCAT, "in message: " + chatMessage.toString());
        // Handle received message
        KrollDict eventData = new KrollDict();
        eventData.put("name", "MESSAGERECEIVED");    
        fireEvent(eventName, eventData);          
    }

    public void transferToButtonInitiated () {
        // Handle transfer to agent
        KrollDict eventData = new KrollDict();
        eventData.put("name", "TRANSFERTOBUTTONINITIATED");    
        fireEvent(eventName, eventData);  
    }

    public void agentIsTyping (boolean isUserTyping) {
        Log.w(LCAT, "agent typing is user: " + isUserTyping);
        // Handle typing update
        KrollDict eventData = new KrollDict();
        eventData.put("name", "AGENTISTYPING");    
        fireEvent(eventName, eventData);  
    }    
}