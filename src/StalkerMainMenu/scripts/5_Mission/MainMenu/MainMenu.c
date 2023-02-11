modded class MainMenu extends UIScriptedMenu {

    override Widget Init() {
        layoutRoot = GetGame().GetWorkspace().CreateWidgets(MMpath);

        m_Play = layoutRoot.FindAnyWidget("play");
        m_CustomizeCharacter = layoutRoot.FindAnyWidget("customize_character");
        m_SettingsButton = layoutRoot.FindAnyWidget("settings");
        m_Exit = layoutRoot.FindAnyWidget("exit");

        m_Version = TextWidget.Cast(layoutRoot.FindAnyWidget("version"));
        m_Stats = new
        MainMenuStats(layoutRoot.FindAnyWidget("stats_root"));
        m_Mission = MissionMainMenu.Cast(GetGame().GetMission());
        m_LastFocusedButton = m_Play;
        m_ScenePC = m_Mission.GetIntroScenePC();

        if (m_ScenePC) {
            m_ScenePC.ResetIntroCamera();
        }

        m_PlayerName = TextWidget.Cast(layoutRoot.FindAnyWidget("character_name"));

        string version;
        GetGame().GetVersion(version);
        m_Version.SetText(version);

        GetGame().GetUIManager().ScreenFadeOut(0);
        SetFocus(null);
        Refresh();
        GetDayZGame().GetBacklit().MainMenu_OnShow();
        g_Game.SetLoadState(DayZLoadState.MAIN_MENU_CONTROLLER_SELECT);

        return layoutRoot;
    }

    override bool OnClick(Widget w, int x, int y, int button) {
        if( button == MouseState.LEFT ) {
            if( w == m_Play ) {
                m_LastFocusedButton = m_Play;
                g_Game.ConnectFromServerBrowser(MMip, MMport, "");
                return true;
            } else if ( w == m_CustomizeCharacter ) {
                OpenMenuCustomizeCharacter();
                return true;
            } else if ( w == m_SettingsButton ) {
                OpenSettings();
                return true;
            } else if ( w == m_Exit ) {
                Exit();
                return true;
            }
        }
        return false;
    }

    void OnChangeCharacter(bool create_character = true) {
        if (m_ScenePC && m_ScenePC.GetIntroCharacter()) {
            int charID = m_ScenePC.GetIntroCharacter().GetCharacterID();
            if (create_character) {
                m_ScenePC.GetIntroCharacter().CreateNewCharacterById(charID);
            }
            m_PlayerName.SetText("#c_welcome" + " " + m_ScenePC.GetIntroCharacter().GetCharacterNameById(charID));
            Widget w = m_CustomizeCharacter.FindAnyWidget(m_CustomizeCharacter.GetName() + "_label");

            if (w) {
                TextWidget text = TextWidget.Cast(w);
                if (m_ScenePC.GetIntroCharacter().IsDefaultCharacter()) {
                    text.SetText("#layout_main_menu_customize_char");
                } else {
                    text.SetText("#layout_main_menu_rename");
                }
            }
            if (m_ScenePC.GetIntroCharacter().GetCharacterObj()) {
                if (m_ScenePC.GetIntroCharacter().GetCharacterObj().IsMale()) {
                    m_ScenePC.GetIntroCharacter().SetCharacterGender(ECharGender.Male);
                } else {
                    m_ScenePC.GetIntroCharacter().SetCharacterGender(ECharGender.Female);
                }
            }
            m_Stats.UpdateStats();
        }
    }

    override void LoadMods() {
        return;
    }

    override void Play() {
        return;
    }
}
