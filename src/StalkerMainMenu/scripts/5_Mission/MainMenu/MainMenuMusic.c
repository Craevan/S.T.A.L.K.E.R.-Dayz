modded class MissionMainMenu {
    override void PlayMusic() {
        ref SoundParams soundParams	= new SoundParams( "FMusic_Menu_SoundSet" );
        ref SoundObjectBuilder soundBuilder	= new SoundObjectBuilder( soundParams );
        ref SoundObject soundObject	= soundBuilder.BuildSoundObject();
        soundObject.SetKind( WaveKind.WAVEMUSIC );
        m_MenuMusic = GetGame().GetSoundScene().Play2D(soundObject, soundBuilder);
        m_MenuMusic.Loop( true );
        m_MenuMusic.Play();
    }
}
