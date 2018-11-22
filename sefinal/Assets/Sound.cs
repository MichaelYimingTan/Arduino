using UnityEngine.Audio;
using UnityEngine;

[System.Serializable]

public class Sound{
    public AudioClip clip;

    public string name;


    [Range(0f,1f)]
    public float volume;


    public bool looping;

    [HideInInspector]
    public AudioSource source;

}
