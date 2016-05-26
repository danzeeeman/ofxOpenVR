#pragma once
#include "ofMain.h"
#include "openvr.h"


class RenderModel
{
public:
	RenderModel(const std::string & sRenderModelName);
	~RenderModel();

	bool BInit(const vr::RenderModel_t & vrModel, const vr::RenderModel_TextureMap_t & vrDiffuseTexture);
	void Cleanup();
	void Draw();
	const std::string & GetName() const { return m_sModelName; }

private:
	GLuint m_glVertBuffer;
	GLuint m_glIndexBuffer;
	GLuint m_glVertArray;
	GLuint m_glTexture;
	GLsizei m_unVertexCount;
	std::string m_sModelName;
};


class ofxOpenVR {
	public:
		ofxOpenVR();
		~ofxOpenVR();
		void setup();
	
		void drawDebug();
		bool initHMD();
		bool initCompositor();
		bool initGL();
		bool HandleInput();
	
		void shutdown();
		void ProcessVREvent(const vr::VREvent_t & event);
		void drawControllers();
		
		void setupRenderModelForTrackedDevice(vr::TrackedDeviceIndex_t unTrackedDeviceIndex);
		bool setupStereoRenderTargets();
		void setupDistortion();
		void setupCameras();
		void setupModels();

		void renderFrame();
		void renderStereoTargets();
		void renderDistortion();
		void beginScene(vr::Hmd_Eye nEye);
		void endScene(vr::Hmd_Eye nEye);
		
		void renderController(vr::Hmd_Eye nEye);
		void renderModels(vr::Hmd_Eye nEye);

		ofMatrix4x4 getHMDMatrixProjectionEye(vr::Hmd_Eye nEye);
		ofMatrix4x4 getHMDMatrixPoseEye(vr::Hmd_Eye nEye);
		ofMatrix4x4 getCurrentViewProjectionMatrix(vr::Hmd_Eye nEye);
		void updateHMDMatrixPose();

		ofMatrix4x4 convertSteamVRMatrixToMatrix4(const vr::HmdMatrix34_t &matPose);
		RenderModel *FindOrLoadRenderModel(const char *pchRenderModelName);
		bool createAllShaders();

		//void setupRenderModelForTrackedDevice(vr::TrackedDeviceIndex_t unTrackedDeviceIndex);
	private:
		vr::IVRSystem *mHMD;
		vr::IVRRenderModels *mRenderModels;
		std::string mStrDriver;
		std::string mStrDisplay;
		vr::TrackedDevicePose_t mTrackedDevicePose[vr::k_unMaxTrackedDeviceCount];
		ofMatrix4x4 mMat4DevicePose[vr::k_unMaxTrackedDeviceCount];
		bool mShowTrackedDevice[vr::k_unMaxTrackedDeviceCount];

		int mTrackedControllerCount;
		int mTrackedControllerCount_Last;
		int mValidPoseCount;
		int mValidPoseCount_Last;
		bool mbShowCubes;

		std::string mstrPoseClasses;                            // what classes we saw poses for this frame
		char mrDevClassChar[vr::k_unMaxTrackedDeviceCount];   // for each device, a character representing its class

		int miSceneVolumeWidth;
		int miSceneVolumeHeight;
		int miSceneVolumeDepth;
		float mfScaleSpacing;
		float mfScale;

		int miSceneVolumeInit;                                  // if you want something other than the default 20x20x20

		float mNearClip;
		float mFarClip;

		uint32_t mWindowWidth;
		uint32_t mWindowHeight;

		struct VertexDataScene
		{
			ofVec3f position;
			ofVec2f texCoord;
		};

		struct VertexDataLens
		{
			ofVec2f position;
			ofVec2f texCoordRed;
			ofVec2f texCoordGreen;
			ofVec2f texCoordBlue;
		};

		ofFbo mLeftEyeRenderFrameBuffer;
		ofFbo mRightEyeRenderFrameBuffer;

		ofFbo mLeftEyeResolveFrameBuffer;
		ofFbo mRightEyeResolveFrameBuffer;

		

		uint32_t mRenderWidth;
		uint32_t mRenderHeight;

		ofShader sceneShader;
		ofShader controllerShader;
		ofShader renderShader;
		ofShader distortionShader;

		GLint mControllerMatrixLocation;
		GLint mSceneMatrixLocation;
		GLint mRenderMatrixLocation;
		bool bIsInputCapturedByAnotherProcess;

		ofMatrix4x4 mMat4HMDPose;
		ofMatrix4x4 mMat4eyePosLeft;
		ofMatrix4x4 mMat4eyePosRight;

		ofMatrix4x4 mMat4ProjectionCenter;
		ofMatrix4x4 mMat4ProjectionLeft;
		ofMatrix4x4 mMat4ProjectionRight;

		vector<ofFbo*> eyes;

		GLuint m_unLensVAO;
		GLuint m_glIDVertBuffer;
		GLuint m_glIDIndexBuffer;
		unsigned int m_uiIndexSize;

		bool mVblank;
		bool mGlFinishHack;

		struct FramebufferDesc
		{
			GLuint m_nDepthBufferId;
			GLuint m_nRenderTextureId;
			GLuint m_nRenderFramebufferId;
			GLuint m_nResolveTextureId;
			GLuint m_nResolveFramebufferId;
		};
		FramebufferDesc leftEyeDesc;
		FramebufferDesc rightEyeDesc;
		bool createFrameBuffer(int nWidth, int nHeight, FramebufferDesc &framebufferDesc);
		//bool createFrameBuffer(uint32_t nWidth, uint32_t nHeight, ofFbo &framebufferDesc);

		GLuint m_glControllerVertBuffer;
		GLuint m_unControllerVAO;
		unsigned int m_uiControllerVertcount;

		std::vector< RenderModel * > m_vecRenderModels;
		RenderModel *mTrackedDeviceToRenderModel[vr::k_unMaxTrackedDeviceCount];

};